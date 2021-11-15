//
//  File.swift
//
//
//  Created by Marcel Kulina on 12.11.21.
//

import Foundation
import ECS


public class AIFlow: Flow {
    @available(macOS 12.0.0, *)
    init() {
        register(flow: self.run)
    }

    public func run() {
    }
}

