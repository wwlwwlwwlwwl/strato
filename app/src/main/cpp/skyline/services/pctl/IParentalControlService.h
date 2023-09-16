// SPDX-License-Identifier: MPL-2.0
// Copyright © 2020 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include <services/serviceman.h>

namespace skyline::service::pctl {
    /**
     * @brief IParentalControlService is used to access parental control configuration
     * @url https://switchbrew.org/wiki/Parental_Control_services#IParentalControlService
     */
    class IParentalControlService : public BaseService {
      public:
        IParentalControlService(const DeviceState &state, ServiceManager &manager);

        /**
         * @brief Initialises the parental control service instance
         */
        Result Initialize(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        Result CheckFreeCommunicationPermission(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        Result EndFreeCommunication(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        Result IsFreeCommunicationAvailable(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        SERVICE_DECL(
            SFUNC(0x1, IParentalControlService, Initialize),
            SFUNC(0x3E9, IParentalControlService, CheckFreeCommunicationPermission),
            SFUNC(0x3F9, IParentalControlService, EndFreeCommunication),
            SFUNC(0x3FA, IParentalControlService, IsFreeCommunicationAvailable)
        )
    };
}
