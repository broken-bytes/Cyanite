// swift-tools-version:5.5

import PackageDescription

let CyaniteScripting = Package(
  name: "CyaniteScripting",
  products: [
    .library(name: "CyaniteScripting", type: .dynamic, targets: ["Internal", "Input", "SDLRaw", "Bridge"]),
  ],
  targets: [
    .target(
      name: "Internal",
      dependencies: [
        "SDLRaw",
        "Bridge"
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
