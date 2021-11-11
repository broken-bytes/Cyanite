
//
//  File.swift
//
//
//  Created by Marcel Kulina on 11.11.21.
//

import Foundation


public typealias OnClickListener = () -> Void

public struct UIButton: UIElement {
    let onClick: OnClickListener
    let text: String
    
    public init(with text: String, onClick: @escaping OnClickListener) {
        self.text = text
        self.onClick = onClick
    }
}
