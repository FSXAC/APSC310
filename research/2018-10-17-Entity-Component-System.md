---
title: Entity-Component-System
date: 2018-10-17
author: Muchen He
---

[TOC]

# Entity-Component-System

- The entity-component-system (ECS) is a software architecture design pattern, commonly used in game development and physics engines. [^1]

- OOP focuses on **composition** over inheritance [^2] where the inherited class is based on function rather than traditional inheritance.



## Definitions

**Entity**

- General purpose object
- Generally has a unique ID

**Component**

- Raw data for some object

**System**

- Each system runs continuously (one could have UI system, AI system, renderer system, etc.)
- that handles all the entities, and performs global actions



## Characteristics

- An **entity manager** handles the life time of entities, it creates and destroys entities




[^1]: https://en.wikipedia.org/wiki/Entity–component–system

[^2]: https://en.wikipedia.org/wiki/Composition_over_inheritance
[^3]: http://gameprogrammingpatterns.com/component.html
[^4]: https://www.gamedev.net/articles/programming/general-and-gameplay-programming/understanding-component-entity-systems-r3013/
[^5]: https://github.com/junkdog/artemis-odb/wiki/Introduction-to-Entity-Systems

