// swift-tools-version:5.5

import PackageDescription

let CyaniteScripting = Package(
  name: "CyaniteScripting",
  products: [
    .library(name: "CyaniteAssembly", type: .dynamic, targets: ["Internal", "Input", "Bridge", "Graphics2D", "Graphics3D", "ECS", "Math", "UI", "Assembly"]),
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
            .unsafeFlags(["-D_OSX"], .when(platforms: [.macOS])),
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
    .target(
      name: "ECS",
      dependencies: [
      ],
      path: "ECS/",
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
      name: "Graphics2D",
      dependencies: [
        "Math"
      ],
      path: "Graphics2D/",
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
      name: "Graphics3D",
      dependencies: [
        "Math"
      ],
      path: "Graphics3D/",
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
      name: "Audio",
      dependencies: [
      ],
      path: "Audio/",
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
      name: "Math",
      dependencies: [
      ],
      path: "Math/",
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
      name: "Time",
      dependencies: [
      ],
      path: "Time/",
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
      name: "UI",
      dependencies: [
      ],
      path: "UI/",
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
      name: "Assembly",
      dependencies: [
        "ECS"
      ],
      path: "Assembly/",
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
  ]
)
