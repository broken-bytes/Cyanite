//
//  File.swift
//  
//
//  Created by Marcel Kulina on 11.11.21.
//

import Foundation


struct Entity {
    var uuid: UInt32
    var components: [Component]
    
    init(with components: [Component]) {
        self.components = components
    }
    
    func add(component: Component) {
        self.components.insert(component)
    }
}
