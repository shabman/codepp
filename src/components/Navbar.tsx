import React from "react";

import "../styles/navbar.css"

const NavbarItem : React.FC<{children : string}> = ({children}) => {
    return (
        <div className="navbar item">
            <span className="navbar item text">{children}</span>
        </div>
    )
}

const Navbar : React.FC = () => {
    return (
        <div className="navbar">
            <NavbarItem>sss</NavbarItem>
        </div>
    )
}

export default Navbar