RAII = Resource Allocation Is Initialization

Common resources - 
- Memory 
- POSIX File
- Joinable threads
- Mutex locks

Issues - 
- Resource leak (you lost the pointer, like memory leak)
- Forget to clean after yourself
- Double disposal