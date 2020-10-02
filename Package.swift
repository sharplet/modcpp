// swift-tools-version:5.3

import PackageDescription

let package = Package(
  name: "modcpp",
  targets: [
    .target(name: "exercise1", path: "src/exercise1"),
    .target(name: "exercise2", path: "src/exercise2"),
  ],
  cxxLanguageStandard: .cxx11
)
