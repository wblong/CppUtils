
#include <filesystem>
#include <optional>
#include <iostream>
#include "utils/args.h"

int main(int argc, char* argv[])
{
    if (argc < 3) {
        std::cout << "please run Main.exe PBCPath H3DPath" << std::endl;
        return -1;
    }
    const std::filesystem::path DataPath = Main_DATA_DIR;
    std::filesystem::path PBCPath = DataPath / "URCAIR_DD";
    std::filesystem::path H3DFile = PBCPath / "DB" / "test.H3D";

    utils::Args args;
    args.addAdditionalOption("PBC_Path", "PBC folder path.", true);
    args.addAdditionalOption("H3D_Path", "Save to H3D file path.", true);
    args.parse(argc, const_cast<char**>(argv), false);
    PBCPath=args.getAdditionalArgument<std::string>("PBC_Path", PBCPath.string());
    H3DFile= args.getAdditionalArgument<std::string>("H3D_Path", H3DFile.string());
    std::cout << "PBC_Path:" << PBCPath << std::endl;
    std::cout << "H3D_Path:" << H3DFile << std::endl;
    return 0;
}


