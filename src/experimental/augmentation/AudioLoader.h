// Copyright 2004-present Facebook. All Rights Reserved.

#pragma once

#include <memory>
#include <random>
#include <string>
#include <vector>

namespace w2l {
namespace augmentation {

class AudioLoader {
 public:
  struct Audio {
    std::vector<float>  data_;
    w2l::SoundInfo info_;
    std::string filename_;
    std::string fullpath_;
  };

  AudioLoader(const std::string& audioDirectoryPath);

  Audio loadRandom();

 private:
  const std::string audioDirectoryPath_;
  std::vector<std::string> audioFilePathVec_;
  std::random_device randomSeedDevice_;
  std::mt19937 randomEngine_{0};
  std::unique_ptr<std::uniform_int_distribution<>> uniformDistribution_;
};

} // namespace augmentation
} // namespace w2l
