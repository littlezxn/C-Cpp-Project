#!/bin/bash

# 1. Color and Configuration Definitions
ACCENT_COLOR="#1a73e8"  # Professional Blue
SUCCESS_COLOR="#2e7d32" # Vibrant Green
WARN_COLOR="#c11515"    # Warning Red
TEXT_MUTED="#5f6368"    # Slate Gray

# 2. Dependency Verification
if ! command -v zenity &> /dev/null; then
    echo "Error: Zenity is required. Install it using: sudo apt install zenity" >&2
    exit 1
fi

if [ "$EUID" -ne 0 ]; then
    echo -e "\033[0;32mSuccess: The script is NOT running with sudo privileges.\033[0m"
    # 3. Dynamic Environment Context
    USER_REAL_NAME=$(getent passwd "$USER" | cut -d: -f5 | cut -d, -f1)
    [ -z "$USER_REAL_NAME" ] && USER_REAL_NAME="$USER"
    OS_NAME=$(grep '^NAME=' /etc/os-release | cut -d= -f2 | tr -d '"')
    SYS_UPTIME=$(uptime -p | sed 's/up //')
    TOTAL_PROJECTS="1"
    
    # 4. Welcome Screen Window
    zenity --info \
      --title="Welcome" \
      --width=450 \
      --height=180 \
      --text="<span size='xx-large' weight='bold' foreground='${ACCENT_COLOR}'>Welcome, ${USER_REAL_NAME}!</span>\n\nThank you for launching the project viewer.\n Running on: <b>$OS_NAME</b>\n\nClick OK to open the Project."
    
    # --- STEP 5: MAIN DASHBOARD LOOP ---
    while true; do
        SELECTED_PROJECT=$(zenity --list \
          --title="Project Explorer Dashboard" \
          --width=750 \
          --height=400 \
          --text="⚡ <b>System Health:</b> Running | 🕒 <b>Uptime:</b> $SYS_UPTIME | 📂 <b>Loaded:</b> $TOTAL_PROJECTS Projects" \
          --column="ID" --column="Project Name" --column="Branch" --column="Status Badge" --column="Description Summary" \
          --print-column=1 \
          "01" "C-Cpp-Project" "main" "🟢 Beginner to Advanced" "Programming in C/C++." \
          "EXIT" "<- EXIT APPLICATION" "-" "-" "Close this program window")
    
        # Exit application handler
        if [ $? -ne 0 ] || [ "$SELECTED_PROJECT" = "EXIT" ] || [ -z "$SELECTED_PROJECT" ]; then
            break
        fi
    
        case "$SELECTED_PROJECT" in
            ("01")
                # --- STEP 6: PROJECT STRUCTURE SUB-MENU LOOP ---
                while true; do
                    PROJECT_STRUCTURE=$(zenity --list \
                        --title="Project Details" \
                        --width=750 \
                        --height=400 \
                        --column="ID" --column="Project Name" --column="Branch" --column="Status Badge" \
                        --print-column=1 \
                        "BACK" "<- GO BACK TO DASHBOARD" "-" "-" \
                        "01" "C" "main" "🟢 Folder: Core C implementations" \
                        "02" "C++" "main" "🟢 Folder: Core C++ implementations" \
                        "03" "main.c" "main" "📄 Main source entry file" \
                        "04" "main.sh" "main" "⚙️ Active interface script" \
                        "05" "README.md" "main" "📝 Project documentation file")
    
                    # Go back to main dashboard
                    if [ $? -ne 0 ] || [ "$PROJECT_STRUCTURE" = "BACK" ] || [ -z "$PROJECT_STRUCTURE" ]; then
                        break
                    fi
    
                    case "$PROJECT_STRUCTURE" in
                        ("01"|"02")
                            # Assign target directory dynamically based on selection
                            if [ "$PROJECT_STRUCTURE" = "01" ]; then
                                TARGET_DIR="./C-Cpp-Project/C" && TARGET_DIR="./C"  # Fallback for local testing
                                DIR_TITLE="C Folder Explorer"
                            else
                                TARGET_DIR="./C-Cpp-Project/Cpp" && TARGET_DIR="./Cpp"  # Fallback for local testing
                                DIR_TITLE="C++ Folder Explorer"
                            fi
    
                            # --- STEP 7: DYNAMIC FILE EXPLORER LOOP (C & C++) ---
                            while true; do
                                if [ ! -d "$TARGET_DIR" ]; then
                                    zenity --error --title="Directory Error" --width=400 \
                                        --text="<span foreground='${WARN_COLOR}'><b>Error:</b> Directory not found at:</span>\n<i>$TARGET_DIR</i>"
                                    break
                                fi
    
                                # Build item list starting with a dedicated Back option
                                FILE_LIST=$(echo -e "BACK\n<- GO BACK TO DETAILS\n-\n")
                                FILE_LIST+=$(find "$TARGET_DIR" -maxdepth 1 -mindepth 1 -printf "%f\n" 2>/dev/null | while read -r filename; do
                                    FILE_SIZE=$(stat -c %s "$TARGET_DIR/$filename" 2>/dev/null || echo "0")
                                    FILE_DATE=$(stat -c %y "$TARGET_DIR/$filename" 2>/dev/null | cut -d'.' -f1)
                                    echo "$filename"
                                    echo "${FILE_SIZE} Bytes"
                                    echo "$FILE_DATE"
                                done)
    
                                SELECTED_FILE=$(echo "$FILE_LIST" | zenity --list \
                                    --title="$DIR_TITLE" \
                                    --width=650 \
                                    --height=400 \
                                    --text="Showing contents of: <b>$TARGET_DIR</b>\nSelect any text or code file to view its code content:" \
                                    --column="File Name" --column="Size" --column="Last Modified" \
                                    --print-column=1)
    
                                # Go back to Project Details menu
                                if [ $? -ne 0 ] || [ "$SELECTED_FILE" = "BACK" ] || [ -z "$SELECTED_FILE" ]; then
                                    break
                                fi
    
                                FULL_PATH="$TARGET_DIR/$SELECTED_FILE"
    
                                # Cat file viewer engine
                                if [ -f "$FULL_PATH" ]; then
                                    zenity --text-info \
                                        --title="Code Viewer: $SELECTED_FILE" \
                                        --width=700 \
                                        --height=550 \
                                       --filename="$FULL_PATH" \
                                        --font="Monospace 10" \
                                        --checkbox="Close File Reader"
                                elif [ -d "$FULL_PATH" ]; then
                                    zenity --warning --title="Type Error" --width=350 \
                                        --text="<b>$SELECTED_FILE</b> is a directory. You can only cat flat files."
                                fi
                            done
                            ;;
    
                        ("03")
                            # Cat file viewer for main.c root file directly
                            ROOT_FILE="./C-Cpp-Project/main.c" && ROOT_FILE="./main.c"
                            if [ -f "$ROOT_FILE" ]; then
                                zenity --text-info --title="Code Viewer: main.c" --width=700 --height=550 --filename="$ROOT_FILE" --font="Monospace 10"
                            else
                                zenity --error --title="File Missing" --text="Could not find file at $ROOT_FILE"
                            fi
                            ;;
    
                        ("04")
                            # Cat active runtime script file safely
                            if [ -f "$0" ]; then
                                zenity --text-info --title="Code Viewer: main.sh" --width=700 --height=550 --filename="$0" --font="Monospace 10"
                            else
                                zenity --error --title="File Missing" --text="Could not read current active script body."
                            fi
                            ;;
    
                        ("05")
                            # Cat README markdown structure documentation
                            README_FILE="./C-Cpp-Project/README.md" && README_FILE="./README.md"
                            if [ -f "$README_FILE" ]; then
                                zenity --text-info --title="Markdown Viewer: README.md" --width=700 --height=550 --filename="$README_FILE" --font="Monospace 10"
                            else
                                zenity --error --title="File Missing" --text="Could not find documentation tracking layouts."
                            fi
                            ;;
                        (*)
                            ;;
                    esac
                done
                ;;
            (*)
                ;;
        esac
    done
else
    echo -e "\033[0;31mError: This script cannot be run with sudo!\033[0m" >&2
    exit 1
fi
;;
