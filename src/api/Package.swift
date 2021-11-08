// swift-tools-version:5.5

import PackageDescription

let CyaniteScripting = Package(
  name: "CyaniteScripting",
  products: [
    .executable(name: "CyaniteScripting", targets: ["Internal", "Input", "ControllerKit", "Bridge"]),
  ],
  targets: [
    .executableTarget(
      name: "Internal",
      dependencies: [
        "Bridge",
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
        "ControllerKit"
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
      name: "ControllerKit",
      dependencies: [
      ],
      path: "CK",
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
      ],
      linkerSettings: [
      ]
    ),
  ]
)
