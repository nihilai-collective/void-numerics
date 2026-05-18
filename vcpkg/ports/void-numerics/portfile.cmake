vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO nihilai-collective/void-numerics
    REF "v${VERSION}"    
    SHA512 02e56d00bb1359b3a0d3c33dfb637de5027c254d8b17f816f5a08d56e92bef10eb391481866e0411931789f93a36dc21a268e86555e26fc90b3150e0cbd8a676
    HEAD_REF main
)

set(VCPKG_BUILD_TYPE release) # header-only

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
)

vcpkg_cmake_install()

vcpkg_install_copyright(FILE_LIST "${SOURCE_PATH}/License.md")
