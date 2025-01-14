#if PROTOCOL_VERSION > 754
#include "protocolCraft/Types/Particles/VibrationParticle.hpp"

namespace ProtocolCraft
{
    VibrationParticle::VibrationParticle()
    {
        
    }
    
    VibrationParticle::~VibrationParticle()
    {
        
    }
    
    std::string VibrationParticle::GetName() const
    {
        return "vibration";
    }
    
    ParticleType VibrationParticle::GetType() const
    {
        return ParticleType::Vibration;
    }

    const VibrationPath& VibrationParticle::GetVibrationPath() const
    {
        return vibration_path;
    }

    void VibrationParticle::SetVibrationPath(const VibrationPath& vibration_path_)
    {
        vibration_path = vibration_path_;
    }
    
    void VibrationParticle::ReadImpl(ReadIterator& iter, size_t& length)
    {
        vibration_path.Read(iter, length);
    }
    
    void VibrationParticle::WriteImpl(WriteContainer& container) const
    {
        vibration_path.Write(container);
    }
    
    const nlohmann::json VibrationParticle::SerializeImpl() const
    {
        nlohmann::json output;

        output["vibration_path"] = vibration_path.Serialize();

        return output;
    }
}
#endif
