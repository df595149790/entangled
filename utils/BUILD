package(default_visibility = ["//visibility:public"])

cc_library(
    name = "export",
    hdrs = ["export.h"],
)

cc_library(
    name = "forced_inline",
    hdrs = ["forced_inline.h"],
)

cc_library(
    name = "files",
    srcs = ["files.c"],
    hdrs = ["files.h"],
    deps = [
        ":logger_helper",
        "//common:errors",
    ],
)

cc_library(
    name = "logger_helper",
    srcs = ["logger_helper.c"],
    hdrs = ["logger_helper.h"],
    copts = ["-DLOGGER_ENABLE"],
    deps = [
        "//common:errors",
        "//utils/handles:lock",
        "@com_github_embear_logger//:logger",
    ],
)

cc_library(
    name = "macros",
    hdrs = ["macros.h"],
)

cc_library(
    name = "merkle",
    srcs = ["merkle.c"],
    hdrs = ["merkle.h"],
    deps = ["//common/sign/v2:iss_curl"],
)

cc_library(
    name = "signed_files",
    srcs = ["signed_files.c"],
    hdrs = ["signed_files.h"],
    deps = [
        "//common:errors",
        "//common/curl-p:trit",
        "//common/kerl",
        "//common/model:bundle",
        "//common/sign:normalize",
        "//common/sign/v1:iss_curl",
        "//common/trinary:trit_long",
        "//common/trinary:tryte_ascii",
        "//utils:merkle",
    ],
)

cc_library(
    name = "system",
    srcs = ["system.c"],
    hdrs = ["system.h"],
)

cc_library(
    name = "time",
    srcs = ["time.c"],
    hdrs = ["time.h"],
)

cc_library(
    name = "hash_maps",
    srcs = ["hash_indexed_map.c"],
    hdrs = ["hash_indexed_map.h"],
    deps = [
        "//common:errors",
        "//common/trinary:flex_trit",
        "//utils/containers/hash:hash243_set",
        "@com_github_uthash//:uthash",
    ],
)
