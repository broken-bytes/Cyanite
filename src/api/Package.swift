// swift-tools-version:5.5

import PackageDescription

let CyaniteScripting = Package(
  name: "CyaniteScripting",
  products: [
    .executable(name: "CyaniteScripting", targets: ["Internal", "Input", "Bridge", "NativeLib"]),
  ],
  dependencies: [
    .package(url: "https://github.com/realm/SwiftLint.git", from: "0.37.0"),
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
        "CMakeLists.txt",
      ],
      swiftSettings: [
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
