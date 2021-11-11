//
//  File.swift
//  
//
//  Created by Marcel Kulina on 11.11.21.
//

import Foundation


public struct UIView {
    var width: Int32
    var height: Int32
    
    public init() {
        self.width = 0
        self.height = 0
    }
    
    public init(width: Int32, height: Int32) {
        self.width = width
        self.height = height
    }
    
    public func push(element: UIElement) {
        
    }
}
