// swift-tools-version:4.1

import PackageDescription

let package = Package(
    name: "libaerospike",
    pkgConfig: "libaerospike",
    products: [
        .library(
            name: "libaerospike",
            targets: ["libaerospike"]
        )
    ],
    dependencies: [

    ],
    targets: [
        .target(
            name: "libaerospike"
        )
    ]
);
