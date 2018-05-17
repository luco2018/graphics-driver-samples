#pragma once

#include "CosKmdAdapter.h"

class CosKmdSoftAdapter : public CosKmAdapter
{
private:

    friend class CosKmAdapter;

    CosKmdSoftAdapter(IN_CONST_PDEVICE_OBJECT PhysicalDeviceObject, OUT_PPVOID MiniportDeviceContext) :
        CosKmAdapter(PhysicalDeviceObject, MiniportDeviceContext)
    {
        // do nothing
    }

    virtual ~CosKmdSoftAdapter()
    {
        // do nothing
    }

    void * operator new(size_t  size);
    void operator delete(void * ptr);

protected:

    virtual void ProcessRenderBuffer(COSDMABUFSUBMISSION * pDmaBufSubmission);

    virtual NTSTATUS Start(
        IN_PDXGK_START_INFO     DxgkStartInfo,
        IN_PDXGKRNL_INTERFACE   DxgkInterface,
        OUT_PULONG              NumberOfVideoPresentSources,
        OUT_PULONG              NumberOfChildren);

    virtual BOOLEAN InterruptRoutine(
        IN_ULONG        MessageNumber);
};