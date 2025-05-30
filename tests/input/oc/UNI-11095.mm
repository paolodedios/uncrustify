// Create one-liners

extern "C" NSBundle*            UnityGetMetalBundle()       {
    return _MetalBundle;
}
extern "C" MTLDeviceRef         UnityGetMetalDevice()       { return _MetalDevice; }
extern "C" MTLCommandQueueRef   UnityGetMetalCommandQueue() { return ((UnityDisplaySurfaceMTL*)GetMainDisplaySurface())->commandQueue; }

extern "C" EAGLContext*         UnityGetDataContextEAGL()   {
    return _GlesContext;
}

// Keep one-liners

extern "C" NSBundle*            UnityGetMetalBundle()       { return _MetalBundle; }
extern "C" MTLDeviceRef         UnityGetMetalDevice()       { return _MetalDevice; }
extern "C" MTLCommandQueueRef   UnityGetMetalCommandQueue() { return ((UnityDisplaySurfaceMTL*)GetMainDisplaySurface())->commandQueue; }

extern "C" EAGLContext*         UnityGetDataContextEAGL()   { return _GlesContext; }
