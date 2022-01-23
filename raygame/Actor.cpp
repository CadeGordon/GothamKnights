#include "Actor.h"
#include "Transform2D.h"
#include <string.h>
#include "Collider.h"
#include "Component.h"

Actor::Actor()
{
    m_transform = new Transform2D(this);
}

Actor::~Actor()
{
    ///Deletes all components
    for (int i = 0; i < m_componentCount; i++)
        delete m_comp[i];

    delete m_transform;
}


Actor::Actor(float x, float y, const char* name = "Actor")
{
    //Initialze default values
    m_transform = new Transform2D(this);
    m_transform->setLocalPosition({ x,y });
    m_name = name;
}

Component* Actor::getComponent(const char* componentName)
{
    //Iterate through the component array
    for (int i = 0; i < m_componentCount; i++)
    {
        //Return the comoponent if the name is the same as the current component
        if (strcmp(m_comp[i]->getName(), componentName) == 0)
            return m_comp[i];
    }

    //Return nullptr if the component is not in the list
    return nullptr;
}

Component* Actor::addComponent(Component* component)
{
    //Return null if this component has an owner already
    Actor* owner = component->getOwner();
    if (owner)
        return nullptr;

    component->assignOwner(this);

    //Create a new array with a size one greater than our old array
    Component** appendedArray = new Component * [m_componentCount + 1];
    //Copy the values from the old array to the new array
    for (int i = 0; i < m_componentCount; i++)
    {
        appendedArray[i] = m_comp[i];
    }

    //Set the last value in the new array to be the actor we want to add
    appendedArray[m_componentCount] = component;
    if (m_componentCount > 1)
        //Set old array to hold the values of the new array
        delete[] m_comp;
    else if (m_componentCount == 1)
        delete m_comp;

    m_comp = appendedArray;
    m_componentCount++;

    return component;
}

bool Actor::removeComponent(Component* component)
{
    if (!component)
        return false;

    bool componentRemoved = false;
    //Create a new array with a size one less than our old array
    Component** newArray = new Component * [m_componentCount - 1];
    //Create variable to access tempArray index
    int j = 0;
    //Copy values from the old array to the new array
    for (int i = 0; i < m_componentCount; i++)
    {
        if (component != m_comp[i])
        {
            newArray[j] = m_comp[i];
            j++;
        }
        else
        {
            componentRemoved = true;
        }
    }

    if (componentRemoved)
    {
        delete[] m_comp;
        //Set the old array to the new array
        m_comp = newArray;
        m_componentCount--;
        delete component;
    }
    else
        delete[] newArray;

    //Return whether or not the removal was successful
    return componentRemoved;
}

bool Actor::removeComponent(const char* name)
{
    if (!name)
        return false;

    bool componentRemoved = false;
    Component* componentToDelete = nullptr;

    //Create a new array with a size one less than our old array
    Component** newArray = new Component * [m_componentCount - 1];
    //Create variable to access tempArray index
    int j = 0;
    //Copy values from the old array to the new array
    for (int i = 0; i < m_componentCount; i++)
    {
        if (strcmp(m_comp[i]->getName(), name) == 0)
        {
            newArray[j] = m_comp[i];
            j++;

            if (m_componentCount == 1)
                componentRemoved = true;
        }
        else
        {
            componentRemoved = true;
            componentToDelete = m_comp[i];
        }
    }

    if (componentRemoved)
    {
        delete[] m_comp;
        //Set the old array to the new array
        m_comp = newArray;
        m_componentCount--;
        delete componentToDelete;
    }
    else
        delete[] newArray;

    //Return whether or not the removal was successful
    return componentRemoved;
}

void Actor::start()
{
    m_started = true;
}

void Actor::onCollision(Actor* other)
{
    for (int i = 0; i < m_componentCount; i++)
        m_comp[i]->onCollision(other);
}

void Actor::update(float deltaTime)
{
    for (int i = 0; i < m_componentCount; i++)
    {
        if (!m_comp[i]->getStarted())
            m_comp[i]->start();

        m_comp[i]->update(deltaTime);
    }
}

void Actor::draw()
{
    for (int i = 0; i < m_componentCount; i++)
        m_comp[i]->draw();
}

void Actor::end()
{
    m_started = false;

    for (int i = 0; i < m_componentCount; i++)
        m_comp[i]->end();
}

void Actor::onDestroy()
{
    for (int i = 0; i < m_componentCount; i++)
        m_comp[i]->onDestroy();

    Transform2D* parent = getTransform()->getParent();

    if (getTransform()->getParent())
        parent->removeChild(getTransform());
}

bool Actor::checkForCollision(Actor* other)
{
    //Call check collision if there is a collider attached to this actor
    if (m_collider)
        return m_collider->checkCollision(other);

    return false;
}