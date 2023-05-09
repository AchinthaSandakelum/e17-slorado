/* @file basecall.h
**
** methods for base calling step
** @@
******************************************************************************/

#ifndef BASECALL
#define BASECALL

#include <vector>

#include "slorado.h"
#include "misc.h"

#include "dorado/decode/Decoder.h"
#include "dorado/nn/ModelRunner.h"
#include "dorado/Chunk.h"

void basecall_chunks(
    std::vector<torch::Tensor> tensors,
    std::vector<Chunk *> chunks,
    int chunk_size,
    ModelRunnerBase &model_runner,
    timestamps_t *ts
);

void basecall_thread(
    core_t* core,
    db_t* db,
    size_t runner_idx,
    size_t start,
    size_t end
);

#endif