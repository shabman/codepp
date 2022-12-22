import React from "react";

import "../styles/header.css"
import * as tempSS from "../assets/tempss.png"

const Header : React.FC = () => {
    return (
        <header className="header">
           <table>
                <tr>
                    <td>
                        <h1>Meet codepp, a modern code editor made with C++.</h1>
                    </td>
                </tr>
           </table>
        </header>
    )
}

export default Header