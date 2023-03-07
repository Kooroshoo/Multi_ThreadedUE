# Multi_ThreadedUE4
 UE4 Multithreading Concepts
 
 - Multi-Threaded Blueprints
 
![primes](https://user-images.githubusercontent.com/26629624/223470379-42907fa8-9257-4d91-b354-75b4562257bf.gif)

This example calculates the first 10000 primes on a seperate thread without impacting performance.

 - Asynchronous Asset Loading
 
![async](https://user-images.githubusercontent.com/26629624/223470581-bdfe6e12-b519-4018-9162-f6bdeea00b01.gif)

This example loads the assets asynchronously to speed up loading speeds.


## Limitations
There are certain limitations when it comes to background threads:

- Can’t send to render thread (Print String, Changing Actor Transforms, Components Transforms etc).
- Can’t spawn AActors or derivatives (The engine doesn't support spawning actors on a background thread. Game thread is used to Async spawn Actors and spread the volume over multiple frames).
- Can’t create UObjects and derivatives.
- Additional attention needs to be paid to Arrays and Maps since you can have thread safety issues if you’rewriting from multiple threads at once.

#
Unreal ver. 4.27
