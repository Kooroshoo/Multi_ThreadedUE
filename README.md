# Multi_ThreadedUE4
 UE4 Multithreading Concepts
 - Multi-Threaded Blueprints
 - Asynchronous Asset Loading



## Limitations
There are certain limitations when it comes to background threads:

- Can’t send to render thread (Print String, Changing Actor Transforms, Components Transforms etc).
- Can’t spawn AActors or derivatives (The engine doesn't support spawning actors on a background thread. Game thread is used to Async spawn Actors and spread the volume over multiple frames).
- Can’t create UObjects and derivatives.
- Additional attention needs to be paid to Arrays and Maps since you can have thread safety issues if you’rewriting from multiple threads at once.

#
Unreal ver. 4.27
