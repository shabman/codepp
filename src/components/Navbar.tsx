import React from "react";

import "../styles/navbar.css"

import AOS from "aos"
import "aos/dist/aos.css"

const NavbarItem : React.FC<{children : string | React.ReactNode}> = ({children}) => {
    return (
        <div className="navbar item">
            <span className="navbar item text">{children}</span>
        </div>
    )
}

const Navbar : React.FC = () => {

    React.useEffect(() => {
        AOS.init()
    }) 
    return (
        <div data-aos="fade-right" className="navbar">
            <div className="navbar head">
                <a className="navbar head a">
                <span>Code++</span>
                </a> 
            </div>
        </div>
    )
}

export default Navbar