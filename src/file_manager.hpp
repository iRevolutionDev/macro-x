#pragma once
#include "file_manager/file.hpp"
#include "file_manager/folder.hpp"

class file_manager final
{
public:
    file_manager() = default;
    virtual ~file_manager() = default;
    file_manager(const file_manager&) = delete;
    file_manager(file_manager&&) noexcept = delete;
    file_manager& operator=(const file_manager&) = delete;
    file_manager& operator=(file_manager&&) noexcept = delete;

    bool init(const std::filesystem::path& base_dir);

    const std::filesystem::path& get_base_dir();

    [[nodiscard]] file get_project_file(const std::filesystem::path& file_path) const;

    [[nodiscard]] folder get_project_folder(const std::filesystem::path& folder_path) const;

    static std::filesystem::path ensure_file_can_be_created(const std::filesystem::path& file_path);
    static std::filesystem::path ensure_folder_exists(const std::filesystem::path& folder_path);

private:
    std::filesystem::path m_base_dir;
};

inline auto g_file_manager = file_manager();