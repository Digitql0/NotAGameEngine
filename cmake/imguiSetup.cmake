function(add_imgui_with_backend target backend)
    set(IMGUI_CORE
        ${PROJECT_SOURCE_DIR}/external/imgui/imgui.cpp
        ${PROJECT_SOURCE_DIR}/external/imgui/imgui_draw.cpp
        ${PROJECT_SOURCE_DIR}/external/imgui/imgui_tables.cpp
        ${PROJECT_SOURCE_DIR}/external/imgui/imgui_widgets.cpp
    )

    if(backend STREQUAL "glfw_opengl3")
        set(IMGUI_BACKEND
            ${PROJECT_SOURCE_DIR}/external/imgui/backends/imgui_impl_glfw.cpp
            ${PROJECT_SOURCE_DIR}/external/imgui/backends/imgui_impl_opengl3.cpp
        )
        target_include_directories(${target} PRIVATE
            ${PROJECT_SOURCE_DIR}/external/imgui
            ${PROJECT_SOURCE_DIR}/external/imgui/backends
        )
    else()
        message(FATAL_ERROR "Unsupported ImGui backend: ${backend}")
    endif()

    target_sources(${target} PRIVATE ${IMGUI_CORE} ${IMGUI_BACKEND})
    target_include_directories(${target} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../external/imgui)
endfunction()

