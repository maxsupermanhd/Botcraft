#pragma once

#include "protocolCraft/BaseMessage.hpp"

namespace ProtocolCraft
{
    class ConfirmTransactionClientbound : public BaseMessage<ConfirmTransactionClientbound>
    {
    public:
        virtual const int GetId() const override
        {
#if PROTOCOL_VERSION == 340 // 1.12.2
            return 0x11;
#elif PROTOCOL_VERSION == 393 || PROTOCOL_VERSION == 401 || PROTOCOL_VERSION == 404 // 1.13.X
            return 0x12;
#elif PROTOCOL_VERSION == 477 || PROTOCOL_VERSION == 480 || PROTOCOL_VERSION == 485 || PROTOCOL_VERSION == 490 || PROTOCOL_VERSION == 498 // 1.14.X
            return 0x12;
#elif PROTOCOL_VERSION == 573 || PROTOCOL_VERSION == 575 || PROTOCOL_VERSION == 578 // 1.15.X
			return 0x13;
#elif PROTOCOL_VERSION == 735 || PROTOCOL_VERSION == 736  // 1.16.0 or 1.16.1
            return 0x12;
#elif PROTOCOL_VERSION == 751 // 1.16.2
            return 0x11;
#else
            #error "Protocol version not implemented"
#endif
        }

        virtual const std::string GetName() const override
        {
            return "Confirm Transaction (clientbound)";
        }

        void SetWindowId(const char window_id_)
        {
            window_id = window_id_;
        }

        void SetActionNumber(const short action_number_)
        {
            action_number = action_number_;
        }

        void SetAccepted(const bool accepted_)
        {
            accepted = accepted_;
        }

        const char GetWindowId() const
        {
            return window_id;
        }

        const short GetActionNumber() const
        {
            return action_number;
        }

        const bool GetAccepted() const
        {
            return accepted;
        }

    protected:
        virtual void ReadImpl(ReadIterator &iter, size_t &length) override
        {
            window_id = ReadData<char>(iter, length);
            action_number = ReadData<short>(iter, length);
            accepted = ReadData<bool>(iter, length);
        }

        virtual void WriteImpl(WriteContainer &container) const override
        {
            WriteData<char>(window_id, container);
            WriteData<short>(action_number, container);
            WriteData<bool>(accepted, container);
        }

        virtual const picojson::value SerializeImpl() const override
        {
            picojson::value value(picojson::object_type, false);
            picojson::object& object = value.get<picojson::object>();

            object["window_id"] = picojson::value((double)window_id);
            object["action_number"] = picojson::value((double)action_number);
            object["accepted"] = picojson::value(accepted);

            return value;
        }

    private:
        char window_id;
        short action_number;
        bool accepted;
    };
} //ProtocolCraft