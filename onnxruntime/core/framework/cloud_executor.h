// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once
#include "core/framework/iexecutor.h"

namespace onnxruntime {

class CloudExecutor : public onnxruntime::IExecutor {
 public:
  CloudExecutor() = default;
  ~CloudExecutor() = default;
  ORT_DISALLOW_COPY_ASSIGNMENT_AND_MOVE(CloudExecutor);

  common::Status Execute(const SessionState& session_state, gsl::span<const int> feed_mlvalue_idxs,
                         gsl::span<const OrtValue> feeds, gsl::span<const int> fetch_mlvalue_idxs,
                         std::vector<OrtValue>& fetches,
                         const std::unordered_map<size_t, CustomAllocator>& fetch_allocators,
                         const logging::Logger& logger) override;
};

}  // namespace onnxruntime