#ifndef __DEVICE_MAP__
#define __DEVICE_MAP__

#include "map_struct.h"
#include "intrinsic_matrix.h"
#include <sophus/se3.hpp>
#include <opencv2/cudaarithm.hpp>

namespace slam
{
namespace map
{

void update(MapStruct map_struct,
            const cv::cuda::GpuMat depth,
            const cv::cuda::GpuMat image,
            const Sophus::SE3d &frame_pose,
            const IntrinsicMatrix intrinsic_matrix,
            uint &visible_block_count);

void create_rendering_blocks(MapStruct map_struct,
                             cv::cuda::GpuMat &zrange_x,
                             cv::cuda::GpuMat &zrange_y,
                             const Sophus::SE3d &frame_pose,
                             const IntrinsicMatrix intrinsic_matrix);

void raycast(MapStruct map_struct,
             cv::cuda::GpuMat vmap,
             cv::cuda::GpuMat nmap,
             cv::cuda::GpuMat zrange_x,
             cv::cuda::GpuMat zrange_y,
             const Sophus::SE3d &pose,
             const IntrinsicMatrix intrinsic_matrix);

} // namespace map
} // namespace slam

#endif