/*
 * Copyright (C) Canonical, Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef MULTIPASS_MOCK_UTILS_H
#define MULTIPASS_MOCK_UTILS_H

#include "common.h"
#include "mock_singleton_helpers.h"

#include <multipass/ssh/ssh_key_provider.h>
#include <multipass/utils.h>
#include <multipass/virtual_machine.h>

namespace multipass::test
{
class MockUtils : public Utils
{
public:
    using Utils::Utils;
    MOCK_METHOD(qint64, filesystem_bytes_available, (const QString&), (const, override));
    MOCK_METHOD(void, exit, (int), (override));
    MOCK_METHOD(std::string, run_cmd_for_output, (const QString&, const QStringList&, const int), (const, override));
    MOCK_METHOD(bool, run_cmd_for_status, (const QString&, const QStringList&, const int), (const, override));
    MOCK_METHOD(void, make_file_with_content, (const std::string&, const std::string&), ());
    MOCK_METHOD(void, make_file_with_content, (const std::string&, const std::string&, const bool&), (override));
    MOCK_METHOD(Path, make_dir, (const QDir&, const QString&, QFileDevice::Permissions), (override));
    MOCK_METHOD(Path, make_dir, (const QDir&, QFileDevice::Permissions), (override));
    MOCK_METHOD(void, wait_for_cloud_init, (VirtualMachine*, std::chrono::milliseconds, const SSHKeyProvider&),
                (const, override));
    MOCK_METHOD(std::string, get_kernel_version, (), (const, override));
    MOCK_METHOD(QString, generate_scrypt_hash_for, (const QString&), (const, override));
    MOCK_METHOD(bool, client_certs_exist, (const QString&), (const));
    MOCK_METHOD(void, copy_client_certs_to_common_dir, (const QString&, const QString&), (const));

    MP_MOCK_SINGLETON_BOILERPLATE(MockUtils, Utils);
};
} // namespace multipass::test
#endif // MULTIPASS_MOCK_UTILS_H
