import React from "react";
import ReactDOM from "react-dom/client"

import "./styles/styles.css"

import { Header } from "./components";
import Navbar from "./components/Navbar";

ReactDOM.createRoot(
    document.getElementById("root") as HTMLElement
).render(
    <React.StrictMode>
        <Navbar/>
        <Header/>
    </React.StrictMode>
)