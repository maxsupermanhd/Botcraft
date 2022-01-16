#include "botcraft/Game/Entities/entities/monster/GiantEntity.hpp"

namespace Botcraft
{
    GiantEntity::GiantEntity()
    {

    }

    GiantEntity::~GiantEntity()
    {

    }


    std::string GiantEntity::GetName() const
    {
        return "Giant";
    }

    EntityType GiantEntity::GetType() const
    {
        return EntityType::Giant;
    }

    double GiantEntity::GetWidth() const
    {
        return 3.6;
    }

    double GiantEntity::GetHeight() const
    {
        return 12.0;
    }


    std::string GiantEntity::GetClassName()
    {
        return "Giant";
    }

    EntityType GiantEntity::GetClassType()
    {
        return EntityType::Giant;
    }

}