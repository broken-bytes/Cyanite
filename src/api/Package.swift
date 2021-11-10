// swift-tools-version:5.5

import PackageDescription

let CyaniteScripting = Package(
  name: "CyaniteScripting",
  products: [
    .library(name: "CyaniteAssembly", type: .dynamic, targets: ["Internal", "Input", "Bridge", "NativeLib"]),
  ],
  targets: [
    .executableTarget(
      name: "Internal",
      dependencies: [
        "Bridge",
        "NativeLib"
      ],
      path: "Internal/",
      exclude: [
        "CMakeLists.txt",
      ],
      swiftSettings: [
        .unsafeFlags(["-D_WINDOWS_"]),
      ],
      linkerSettings: [
        .linkedLibrary("User32"),
        .linkedLibrary("ComCtl32"),
      ]
    ),
    .target(
      name: "Input",
      dependencies: [
      ],
      path: "Input/",
      exclude: [
      ],
      swiftSettings: [
            .unsafeFlags(["-L", "./"]),
            .unsafeFlags(["-I", "./"]),
            .unsafeFlags(["-lCyanite"]),
      ],
      linkerSettings: [
      ]
    ),
    .target(
      name: "Bridge",
      dependencies: [
      ],
      path: "Bridge/",
      exclude: [
      ],
      cSettings: [
      ],
      swiftSettings: [
      ],
      linkerSettings: [
      ]
    ),
     .target(
      name: "NativeLib",
      dependencies: [
      ],
      path: "Native/",
      exclude: [
      ],
      cSettings: [

      ],
      swiftSettings: [
      ]
    ),
  ]
)
