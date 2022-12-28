-- This file was generated automatically by OpenGEODE: DO NOT MODIFY IT !

with System.IO;
use System.IO;

with Ada.Unchecked_Conversion;
with Ada.Numerics.Generic_Elementary_Functions;

package body State_Handler_Entrypoint is
   procedure poll_aoi is
      begin
         case ctxt.state is
            when asn1Sccwait =>
               Execute_Transition (5);
            when others =>
               Execute_Transition (CS_Only);
         end case;
      end poll_aoi;
      

   procedure poll_mcp is
      begin
         case ctxt.state is
            when asn1Sccwait =>
               Execute_Transition (6);
            when others =>
               Execute_Transition (CS_Only);
         end case;
      end poll_mcp;
      

   procedure toggle_pwr is
      begin
         case ctxt.state is
            when asn1Sccwait =>
               Execute_Transition (3);
            when asn1Sccsleep =>
               Execute_Transition (2);
            when others =>
               Execute_Transition (CS_Only);
         end case;
      end toggle_pwr;
      

   procedure trig_aoi is
      begin
         case ctxt.state is
            when asn1Sccwait =>
               Execute_Transition (5);
            when others =>
               Execute_Transition (CS_Only);
         end case;
      end trig_aoi;
      

   procedure trig_mcp is
      begin
         case ctxt.state is
            when asn1Sccwait =>
               Execute_Transition (6);
            when others =>
               Execute_Transition (CS_Only);
         end case;
      end trig_mcp;
      

   procedure trig_pwr is
      begin
         case ctxt.state is
            when asn1Sccwait =>
               Execute_Transition (4);
            when asn1Sccsleep =>
               Execute_Transition (1);
            when others =>
               Execute_Transition (CS_Only);
         end case;
      end trig_pwr;
      

   procedure Execute_Transition (Id : Integer) is
      trId : Integer := Id;
      begin
         while (trId /= -1) loop
            case trId is
               when 0 =>
                  --  writeln("[state_handler_entrypoint] Initialising SDL implementation") (15,13)
                  Put ("[state_handler_entrypoint] Initialising SDL implementation");
                  New_Line;
                  --  k_max := 999 (17,13)
                  ctxt.k_max := 999;
                  --  s_max := 3 (19,13)
                  ctxt.s_max := 3;
                  --  w_max := 1 (21,13)
                  ctxt.w_max := 1;
                  --  NEXT_STATE Wait (23,18) at 522, 277
                  trId := -1;
                  ctxt.State := asn1SccWait;
                  goto Continuous_Signals;
               when 1 =>
                  --  JOIN wake (29,17) at 2311, 340
                  goto wake;
               when 2 =>
                  --  s := (s+1) mod (s_max+1) (33,17)
                  ctxt.s := ((ctxt.s + 1) mod (ctxt.s_max + 1));
                  --  DECISION s = s_max (35,23)
                  --  ANSWER false (37,17)
                  if not ((ctxt.s = ctxt.s_max)) then
                     --  NEXT_STATE Sleep (39,30) at 2212, 508
                     trId := -1;
                     ctxt.State := asn1SccSleep;
                     goto Continuous_Signals;
                     --  ANSWER true (41,17)
                  else
                     --  JOIN wake (None,None) at None, None
                     goto wake;
                  end if;
                  --  NEXT_STATE Wait (50,22) at 2101, 714
                  trId := -1;
                  ctxt.State := asn1SccWait;
                  goto Continuous_Signals;
               when 3 =>
                  --  w := (w+1) mod (w_max+1) (57,17)
                  ctxt.w := ((ctxt.w + 1) mod (ctxt.w_max + 1));
                  --  DECISION w = w_max (59,23)
                  --  ANSWER false (61,17)
                  if not ((ctxt.w = ctxt.w_max)) then
                     null;
                     --  ANSWER true (63,17)
                  else
                     --  JOIN sleep (None,None) at None, None
                     goto sleep;
                  end if;
                  --  NEXT_STATE Wait (74,22) at 1635, 713
                  trId := -1;
                  ctxt.State := asn1SccWait;
                  goto Continuous_Signals;
               when 4 =>
                  --  JOIN sleep (78,17) at 1835, 340
                  goto sleep;
               when 5 =>
                  --  request_loc(lfp) (85,17)
                  RI_0_request_loc(ctxt.lfp);
                  --  writeln("[state_handler_entrypoint] [poll_aoi] printout:") (87,17)
                  Put ("[state_handler_entrypoint] [poll_aoi] printout:");
                  New_Line;
                  --  writeln("    k: ", k) (89,17)
                  Put ("    k: ");
                  Put (asn1SccCounterK'Image (ctxt.k));
                  New_Line;
                  --  writeln("    t: ", lfp.t) (91,17)
                  Put ("    t: ");
                  Put (asn1SccTime_UNIX'Image (ctxt.lfp.t));
                  New_Line;
                  --  writeln("    lat: ", lfp.lat) (93,17)
                  Put ("    lat: ");
                  Put (asn1SccLatitude_WGS84'Image (ctxt.lfp.lat));
                  New_Line;
                  --  writeln("    lon: ", lfp.lon) (95,17)
                  Put ("    lon: ");
                  Put (asn1SccLongitude_WGS84'Image (ctxt.lfp.lon));
                  New_Line;
                  --  writeln("") (97,17)
                  Put ("");
                  New_Line;
                  --  send_tm_aoi(lfp) (99,19)
                  RI_0_send_tm_aoi(ctxt.lfp);
                  --  k := (k+1) mod (k_max+1) (101,17)
                  ctxt.k := ((ctxt.k + 1) mod (ctxt.k_max + 1));
                  --  NEXT_STATE Wait (103,22) at 1159, 781
                  trId := -1;
                  ctxt.State := asn1SccWait;
                  goto Continuous_Signals;
               when 6 =>
                  --  request_tc(mcp) (107,17)
                  RI_0_request_tc(ctxt.mcp);
                  --  writeln("[state_handler_entrypoint] [poll_mcp] printout:") (109,17)
                  Put ("[state_handler_entrypoint] [poll_mcp] printout:");
                  New_Line;
                  --  writeln("    k: ", k) (111,17)
                  Put ("    k: ");
                  Put (asn1SccCounterK'Image (ctxt.k));
                  New_Line;
                  --  writeln("    target-addr: ", mcp.target_addr) (113,17)
                  Put ("    target-addr: ");
                  Put (ctxt.mcp.target_addr'Img);
                  New_Line;
                  --  writeln("    target-mode: ", mcp.target_mode) (115,17)
                  Put ("    target-mode: ");
                  Put (ctxt.mcp.target_mode'Img);
                  New_Line;
                  --  writeln("    ttl-ms:", mcp.ttl_ms) (117,17)
                  Put ("    ttl-ms:");
                  Put (asn1SccMode_Change_Packet_ttl_ms'Image (ctxt.mcp.ttl_ms));
                  New_Line;
                  --  writeln("") (119,17)
                  Put ("");
                  New_Line;
                  --  send_tm_mcp(mcp) (121,19)
                  RI_0_send_tm_mcp(ctxt.mcp);
                  --  k := (k+1) mod (k_max+1) (123,17)
                  ctxt.k := ((ctxt.k + 1) mod (ctxt.k_max + 1));
                  --  NEXT_STATE Wait (125,22) at 756, 781
                  trId := -1;
                  ctxt.State := asn1SccWait;
                  goto Continuous_Signals;
               when CS_Only =>
                  trId := -1;
                  goto Continuous_Signals;
               when others =>
                  null;
            end case;
            goto Continuous_Signals;
            --  CONNECTION wake (43,20)
            <<wake>>
            --  writeln("[state_handler_entrypoint] waking up") (45,25)
            Put ("[state_handler_entrypoint] waking up");
            New_Line;
            --  writeln("") (47,25)
            Put ("");
            New_Line;
            --  NEXT_STATE Wait (50,22) at 2101, 714
            trId := -1;
            ctxt.State := asn1SccWait;
            goto Continuous_Signals;
            --  CONNECTION sleep (65,20)
            <<sleep>>
            --  writeln("[state_handler_entrypoint] going to sleep") (67,25)
            Put ("[state_handler_entrypoint] going to sleep");
            New_Line;
            --  writeln("") (69,25)
            Put ("");
            New_Line;
            --  NEXT_STATE Sleep (71,30) at 1522, 648
            trId := -1;
            ctxt.State := asn1SccSleep;
            goto Continuous_Signals;
            <<Continuous_Signals>>
            <<Next_Transition>>
         end loop;
      end Execute_Transition;
      

   procedure Startup is
      begin
         Execute_Transition (0);
         ctxt.Init_Done := True;
      end Startup;
   begin
      Startup;
end State_Handler_Entrypoint;