set(VCPKG_BUILD_TYPE release) # header-only

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO nihilai-collective/void-numerics
    REF "v${VERSION}"
    SHA512 6f31a09e50a87140faf4d056fb4b0a4f4257a7bb1100968955e668ff39a9ffbf710f5c7a6528c5a0682cfe7929f347dfe3074ec4679c51c210673f6682b49457
    HEAD_REF main
)

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
)

vcpkg_cmake_install()

vcpkg_cmake_config_fixup(CONFIG_PATH share/void-numerics)

vcpkg_install_copyright(FILE_LIST "${SOURCE_PATH}/License.md")
