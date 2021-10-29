// swift-tools-version:5.5

import PackageDescription

let CyaniteScripting = Package(
  name: "CyaniteScripting",
  products: [
    .library(name: "CyaniteScripting", type: .dynamic, targets: ["Internal", "Input", "SDLRaw"]),
  ],
  targets: [
    .target(
      name: "Internal",
      dependencies: [
        "SDLRaw"
      ],
      path: "Internal/",
      exclude: [
        "CMakeLists.txt",
      ],
      swiftSettings: [
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
        "CMakeLists.txt",
      ],
      swiftSettings: [
      ],
      linkerSettings: [
      ]
    ),
    .target(
      name: "SDLRaw",
      dependencies: [
      ],
      path: "SDLRaw/",
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
