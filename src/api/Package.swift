// swift-tools-version:5.5

import PackageDescription

let CyaniteScripting = Package(
  name: "CyaniteScripting",
  products: [
    .library(name: "CyaniteAssembly", type: .dynamic, targets: ["Internal", "Input", "Bridge"]),
  ],
  targets: [
    .target(
      name: "Internal",
      dependencies: [
        "Bridge"
      ],
      path: "Internal/",
      exclude: [
      ],
      swiftSettings: [
            .unsafeFlags(["-L", "./"]),
            .unsafeFlags(["-I", "./"]),
            .unsafeFlags(["-lCyaniteCore"]),
            .unsafeFlags(["-D_WIN32"], .when(platforms: [.windows])),
      ],
      linkerSettings: [
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
            .unsafeFlags(["-lCyaniteCore"]),
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
  ]
)
