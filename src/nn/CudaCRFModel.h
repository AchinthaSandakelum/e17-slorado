#pragma once

#include "ModelRunner.h"

#include <c10/cuda/CUDAStream.h>
#include <torch/torch.h>

#include <memory>
#include <vector>

class CudaCaller;

std::shared_ptr<CudaCaller> create_cuda_caller(const std::string& model_path,
                                               int chunk_size,
                                               int batch_size,
                                               const std::string& device);

class CudaModelRunner : public ModelRunnerBase {
public:
    CudaModelRunner(std::shared_ptr<CudaCaller> caller, int chunk_size, int batch_size);
    void accept_chunk(int chunk_idx, at::Tensor slice) final;
    torch::Tensor call_chunks() final;
    size_t model_stride() const final;
    size_t chunk_size() const final;

private:
    std::shared_ptr<CudaCaller> m_caller;
    c10::cuda::CUDAStream m_stream;
    torch::Tensor m_input;
    torch::Tensor m_output;
};
