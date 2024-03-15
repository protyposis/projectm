#include "Factory.hpp"

#include "IdlePreset.hpp"
#include "MilkdropPreset.hpp"
#include <android/log.h>

namespace libprojectM {
namespace MilkdropPreset {

std::unique_ptr<::libprojectM::Preset> Factory::LoadPresetFromFile(const std::string& filename)
{
    __android_log_print(ANDROID_LOG_DEBUG, "PRJMNATIVE", "Factory::LoadPresetFromFile 1");
    std::string path;
    auto protocol = PresetFactory::Protocol(filename, path);
    __android_log_print(ANDROID_LOG_DEBUG, "PRJMNATIVE", "Factory::LoadPresetFromFile 2");
    if (protocol == "idle")
    {
        __android_log_print(ANDROID_LOG_DEBUG, "PRJMNATIVE", "Factory::LoadPresetFromFile 3");
        return IdlePresets::allocate();
    }
    else if (protocol == "" || protocol == "file")
    {
        __android_log_print(ANDROID_LOG_DEBUG, "PRJMNATIVE", "Factory::LoadPresetFromFile 4");
        return std::make_unique<MilkdropPreset>(path);
    }
    else
    {
        __android_log_print(ANDROID_LOG_DEBUG, "PRJMNATIVE", "Factory::LoadPresetFromFile 5");
        // ToDO: Throw unsupported protocol exception instead to provide more information.
        return nullptr;
    }
}

std::unique_ptr<Preset> Factory::LoadPresetFromStream(std::istream& data)
{
    return std::make_unique<MilkdropPreset>(data);
}

} // namespace MilkdropPreset
} // namespace libprojectM
