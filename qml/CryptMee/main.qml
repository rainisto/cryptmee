import QtQuick 2.0
import Sailfish.Silica 1.0

PageStackWindow {
    id: appWindow

    initialPage: startPage    

    /////////////////////// Init all pages ///////////////////
    MainPage {
        id: mainPage
    }

    MailPage {
        id: mailPage
    }

    MailViewer {
        id: mailViewPage
    }

    PasswordInputPage {
        id: passwordDialog
    }

    PubKeySelectionPage {
        id: keyDialog
    }

    StartPage {
        id: startPage
    }

    KeyPage {
        id: keyPage
    }

    SettingsPage {
        id: settingsPage
    }

    KeySearchResultSelectionPage {
        id: searchKeyDialog
    }

    GpgHistoryViewPage {
        id: gpgHistoryPage
    }

    /////////////////////////////////////////////////////////////





}
