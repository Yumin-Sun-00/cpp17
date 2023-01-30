// Objects that exist only while a block is executing are known as automatic objects.

// global objects are allocated at program start up
// destroyed when program ends

// local, automatic objects arre created and destroyed
// when the block in which they are defined is entered and exited

// local static are allocated before their FIRST USE
// destroyed when the program ends (main() end)

// dynamic objects have lifetime that is independent of where they are created
// they exist until they are explicitly freed

// static memory
// used to local static objects, class static members, variables defined outside any functions

// stack memory
// used for nonstatic objects defined inside functions

// objects allocated in static or stack memory is automatically created and destroyed by the compiler
// static objects are allocated before they are used, and destroyed when the program ends


// dynamic allocate: allocate on runtime
