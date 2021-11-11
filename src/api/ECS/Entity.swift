//
//  File.swift
//  
//
//  Created by Marcel Kulina on 11.11.21.
//

import Foundation


public struct Entity {
    var uuid: String
    var components: [Component]
    
    init(with components: [Component]) {
        self.uuid = UUID().uuidString
        self.components = components
    }
    
    mutating func add(component: Component) {
        self.components.append(component)
    }
}
