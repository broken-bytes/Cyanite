// swift-tools-version:5.3

import PackageDescription

let CyaniteScripting = Package(
  name: "CyaniteScripting",
  products: [
    .library(name: "CyaniteScripting", type: .dynamic, targets: ["Input"]),
  ],
  dependencies: [
  ],
  targets: [
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
    )
  ]
)
