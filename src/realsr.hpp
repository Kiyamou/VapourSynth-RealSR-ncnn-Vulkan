// realsr implemented with ncnn library

#ifndef REALSR_HPP
#define REALSR_HPP

#include <string>

// ncnn
#include "net.h"
#include "gpu.h"
#include "layer.h"

constexpr int CHANNELS = 3;

class RealSR
{
public:
    RealSR(int gpuid, bool _tta_mode);
    ~RealSR();

    int load(const std::string& parampath, const std::string& modelpath);
    int process(const float* srcpR, const float* srcpG, const float* srcpB, float* dstpR, float* dstpG, float* dstpB, int width, int height, int src_stride, int dst_stride) const;

public:
    int scale;
    int tilesize_x;
    int tilesize_y;
    int prepadding;

private:
    ncnn::VulkanDevice* vkdev;
    ncnn::Net net;
    ncnn::Pipeline* realsr_preproc;
    ncnn::Pipeline* realsr_postproc;
    bool tta_mode;
};

#endif // REALSR_HPP
