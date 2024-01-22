include(FetchContent)

message("Sirius")
FetchContent_Declare(
        sirius
        GIT_REPOSITORY https://github.com/iRevolutionDev/Sirius.git
        GIT_TAG        main
        GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(sirius)