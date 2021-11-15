//
//  File.swift
//  
//
//  Created by Marcel Kulina on 12.11.21.
//

import Foundation
import ECS
import SystemInfo


public class PlayerFlow: Flow {
    @available(macOS 12.0.0, *)
    init() {
        register(flow: self.run)
        print(cpuCores())
    }

    public func run() {
    }
}

