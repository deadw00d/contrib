REDC     
   WNDW      
Q   WIN_NewDrawer_ID               window.class     n   Add a new drawer   MSGID_WINTITLE_NEWDRAWER                                                 P       P     P             P
Qz      j @         GADG      
Qz   GROUP_NewDrawer_ID         GROP         layout.childs CHLD   
Q1\                   layout.gadget     p        p%      p&      p                 GROP         layout.childs CHLD   
Q2l                   layout.gadget     p                    layout.childs            GADGCHLD   
Q4,   TextLine_EnterName               button.gadget     )      	   #Enter Name for a new Drawer in '%s'    MSGID_LABEL_ENTERNAME                                    layout.childs                 GADGCHLD   
Q6                   space.gadget                layout.childs                 GROP         layout.childs CHLD   
Q8T                   layout.gadget     p                     layout.childs            GADGCHLD   
Q9Ì   String_NewDrawer               string.gadget                   New_Drawer_Name    MSGID_NEWNAME_DEFAULT           ÿ                 layout.childs     q   d     q
Q=´            IMGDCHLD   
Q=´   Label_NewDrawer    
            label.image          `   
New Drawer   MSGID_LABEL_NEWDRAWER        `                       GROP         layout.childs CHLD   
Q?Ô       	            layout.gadget     p                     layout.childs            GADGCHLD   
QAt   CheckBox_CreateIcon                checkbox.gadget                $      %      	   Create _Icon   MSGID_GADGETTEXT_CREATEICON                                 layout.childs                     IMGDCHLD   
QCô                   bevel.image    `                         layout.childs     q   d            GROP         buttonlayout.childs CHLD   
QF                   layout.gadget     p         p        p                  layout.childs     q                GADGCHLD   
QHD   OkButton               button.gadget     	   _Ok    MSGID_BUTTON_OK                   $                  buttonlayout.childs     q                      GADGCHLD   
QK4   Cancelbutton               button.gadget     	   _Cancel    MSGID_BUTTON_CANCEL                   $      %                  buttonlayout.childs     q                                   IMGS    ICTS    REQS      
M,   REQ_ReportError_ID               requester.class    E         E     _Ok   MSGID_REQ_OK  	    E    NewDrawer Error    MSGID_TITLE_ERRORREQ      E    #Could not create new drawer
'%s'
%s    MSGID_ERRORREQ_BODYTEXT            MISC    EDOC