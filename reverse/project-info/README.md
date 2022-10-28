<!DOCTYPE html>
<html lang="en">
<body class="article">
<div id="header">
<h1>170D WOBC Module K Exam II-A</h1>
</div>
<div id="content">
<div class="sect1">
<h2 id="_reverse_man_in_the_middle"><code>reverse</code>: Man in the Middle</h2>
<div class="sectionbody">
<div class="paragraph">
<p>In a secret underground bunker we have uncovered an obelisk of unknown origin. The obelisk has a dialing mechanism
capable of sending data to the far reaches of the universe. We&#8217;ve recently discovered that we&#8217;re not
the only ones using the obelisk, there is communication that appears to be transmitting to a point just outside
our solar system. Fortunately the communication is using an unsecure version of TLS that we&#8217;ve been able to decrypt.
What we&#8217;ve found in the decrypted payload is unsettling. It&#8217;s clear that the messages are directing an armada towards earth.
They&#8217;re not friendly.</p>
</div>
<div class="paragraph">
<p>We believe we can avoid extinction by executing a man in the middle attack, modifying the encrypted traffic to send the
agressors back from where they came.</p>
</div>
<div class="paragraph">
<p>You will be provided with a <code>.pcap</code> containing one or more packets of encrypted conversation. As well as the decryption
key needed to decrypt the payload. To help, you will also be provided with a library to link against to perform the
encryption and decryption.</p>
</div>
<div class="paragraph">
<p>Your task is to write a command line utility (<code>reverse</code>) that will decrypt each message in the <code>.pcap</code>, reverse the direction
commands, re-encrypt, and write the result back out to <code>out.pcap</code>. If the payload contains a message we need to print the
message to <code>STDOUT</code> without the padding. We will then prepend the message with <code>"Don't "</code> and reinsert into the <code>out.pcap</code> conversation.</p>
</div>
<div class="paragraph">
<p>The command will be called as follows:</p>
</div>
<div class="literalblock">
<div class="content">
<pre>reverse &lt;128-bit key&gt; &lt;input file&gt;</pre>
</div>
</div>
<div class="paragraph">
<p>ex:</p>
</div>
<div class="literalblock">
<div class="content">
<pre>reverse df290c80bb7f9ecb08d4a6b3030951aa input.pcap
reverse 0dedd2d9229a260285cb491845010efc simple_input.pcap</pre>
</div>
</div>
<div style="page-break-after: always;"></div>
</div>
</div>
<div class="sect1">
<h2 id="_dice_rubric">DIcE Rubric</h2>
<div class="sectionbody">
<table class="tableblock frame-all grid-all stretch">
<colgroup>
<col style="width: 17.647%;">
<col style="width: 17.647%;">
<col style="width: 58.8235%;">
<col style="width: 5.8825%;">
</colgroup>
<tbody>
<tr>
<td class="tableblock halign-center valign-middle" rowspan="14"><p class="tableblock"><strong>Document</strong></p></td>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">Design Plan</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Does the design plan provide a clear general overview of the project?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">3%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Is the design plan easy to understand?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">2%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top" rowspan="3"><p class="tableblock">Test Plan</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Are test cases detailed enough to repeat easily?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">2%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Are expected results stated clearly?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">2%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Are requirements adequately covered by test cases?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">1%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">Project Writeup</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Does the writeup document challenges and successes encountered?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">2%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Does the writeup document any lessons learned?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">3%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">Writing</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Is the project free of grammatical and spelling errors?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">4%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Is non-code formatting consistent?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">1%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top" rowspan="4"><p class="tableblock">Code Formatting</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Does code conform to the Barr-C?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">4%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Are appropriate names chosen to enable code readability?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">2%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Are comments added where appropriate and aid understanding of the logic?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">2%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Is any outside code cited appropriately?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">2%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top" colspan="2"><p class="tableblock"><strong>Total</strong></p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock"><strong>30%</strong></p></td>
</tr>
<tr>
<td class="tableblock halign-center valign-middle" rowspan="10"><p class="tableblock"><strong>Implement</strong></p></td>
<td class="tableblock halign-left valign-top" rowspan="3"><p class="tableblock">Version Control</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Does the project have the correct name and default branch?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">1%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Were commits broken down into appropriate scopes?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">3%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Are commit messages simple and informative?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">1%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top" rowspan="4"><p class="tableblock">Architecture</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Are effective and efficient data structures used?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">5%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Was the code designed and constructed in a modular fashion?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">10%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Were generally sound decisions made with regard to architecture?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">10%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Can the project be compiled with <code>gcc -Wall</code> no warnings?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">5%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">Testing</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Does the program include robust unit tests?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">4%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Do all automated tests pass when run from <code>make check</code>?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">1%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top" colspan="2"><p class="tableblock"><strong>Total</strong></p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock"><strong>40%</strong></p></td>
</tr>
<tr>
<td class="tableblock halign-center valign-middle" rowspan="10"><p class="tableblock"><strong>Execute</strong></p></td>
<td class="tableblock halign-left valign-top" rowspan="3"><p class="tableblock">Safety</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Does the program avoid crashing or infinite loops, even on invalid input?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">5%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Does the program correctly clean up allocated memory?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">2%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Does the program avoid dereferencing incorrectly?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">3%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Parsing</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Does the program pass <code>make all</code> with no warnings?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">5%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">Requirements</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Were all inputs parsed correctly and yield the correct output?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">5%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Are all other requirements met?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">5%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top" rowspan="2"><p class="tableblock">Performance</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Does the program scale appropriately with input and data?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">3%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Does the program execute in a timely manner?</p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock">2%</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top" colspan="2"><p class="tableblock"><strong>Total</strong></p></td>
<td class="tableblock halign-right valign-top"><p class="tableblock"><strong>30%</strong></p></td>
</tr>
</tbody>
</table>
<table class="tableblock frame-all grid-all stretch">
<colgroup>
<col style="width: 14.2857%;">
<col style="width: 85.7143%;">
</colgroup>
<thead>
<tr>
<th class="tableblock halign-center valign-top">Area</th>
<th class="tableblock halign-center valign-top">Requirement</th>
</tr>
</thead>
<tbody>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Document</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">All documentation must be in PDF format unless otherwise specified.</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Document</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">All documentation must be located in a <code>doc/</code> folder at the top level of the project.</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Document</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">The design document must be located in <code>doc/design.pdf</code></p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Document</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">The test plan must be located in <code>doc/testplan.pdf</code></p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Document</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">The project writeup must be located in <code>doc/writeup.pdf</code></p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Document</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">All code must conform to Barr-C.</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Implement</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Project must be stored in the assigned VCS account, under the project name <code>reverse</code>.</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Implement</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">No third-party header files/libraries may be used unless signed off by the Program Manager or Instructor.</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Implement</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Project must use appropriate data types or structures, and relationships between them.</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Implement</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">All automated tests and test code must be located in a <code>test/</code> folder at the top level.</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Implement</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Project must provide appropriate automated unit tests.</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Implement</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Project must compile without errors or warnings with <code>gcc</code>.</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Implement</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">A valid makefile must be provided that correctly compiles the project.</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Implement</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Implement parsing all Alien Message Payloads explained below.</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Implement</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">The Sequence IDs in the alien packet must be updated to match the reversed directions.</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Implement</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Reversed Alien Packet Movements must be written into the output <code>.pcap</code>.</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Implement</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Packets of Message type must be prepended with <code>"Don't "</code> and writen into the output <code>.pcap</code>.</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Implement</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Packets of message type must be printed to <code>STDOUT</code> preceded by the Destination ID.</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Execute</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Project must run on the class machine.</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Execute</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Project must not crash or get stuck in an infinite loop, even on invalid input.</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Execute</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Project must be invoked as <code>reverse</code> from the top level directory of the repository.</p></td>
</tr>
</tbody>
</table>
<div style="page-break-after: always;"></div>
</div>
</div>
<div class="sect1">
<h2 id="_suggested_implementation">Suggested Implementation</h2>
<div class="sectionbody">
<div class="olist arabic">
<ol class="arabic">
<li>
<p>Read the key and input <code>.pcap</code> filename from the command line.</p>
</li>
<li>
<p>Parse the binary <code>.pcap</code> file and for each TLS section extract the encrypted message.</p>
</li>
<li>
<p>Pass the encrypted message to the library.</p>
</li>
<li>
<p>Parse the returned decrypted contents.</p>
<div class="ulist">
<ul>
<li>
<p>If the packet is Message type print Destination ID and the message to <code>STDOUT</code>.</p>
<div class="olist lowerroman">
<ol class="lowerroman" type="i">
<li>
<p>Make the first character lowercase and prepend the message in frame with <code>"Don't "</code>.</p>
</li>
<li>
<p>Update the padding</p>
</li>
</ol>
</div>
</li>
<li>
<p>If the packet is a Movement type reverse the movement operation.</p>
</li>
</ul>
</div>
</li>
<li>
<p>Pass rebuilt frame to library for re-encryption.</p>
</li>
<li>
<p>Write the re-encrypted and re-sequenced conversation to <code>out.pcap</code>.</p>
</li>
</ol>
</div>
<div class="admonitionblock note">
<table>
<tr>
<td class="icon">
<div class="title">Note</div>
</td>
<td class="content">
The ordering in the <code>.pcap</code> is not important, just make sure that the Sequence IDs are updated appropriately.
</td>
</tr>
</table>
</div>
<div class="admonitionblock tip">
<table>
<tr>
<td class="icon">
<div class="title">Tip</div>
</td>
<td class="content">
For simplicity the TCP packets will be in order, however the Alien Packets might be out of sequence.
</td>
</tr>
</table>
</div>
</div>
</div>
<div class="sect1">
<h2 id="_pcap_encoding_format"><code>.pcap</code> Encoding Format</h2>
<div class="sectionbody">
<table class="tableblock frame-all grid-all stretch">
<colgroup>
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9437%;">
</colgroup>
<tbody>
<tr>
<th class="tableblock halign-left valign-top"><p class="tableblock">Offsets</p></th>
<th class="tableblock halign-left valign-top"><p class="tableblock">Octet</p></th>
<td class="tableblock halign-left valign-top" colspan="8"><p class="tableblock">0</p></td>
<td class="tableblock halign-left valign-top" colspan="8"><p class="tableblock">1</p></td>
<td class="tableblock halign-left valign-top" colspan="8"><p class="tableblock">2</p></td>
<td class="tableblock halign-left valign-top" colspan="8"><p class="tableblock">3</p></td>
</tr>
<tr>
<th class="tableblock halign-left valign-top"><p class="tableblock">File Offset</p></th>
<th class="tableblock halign-left valign-top"><p class="tableblock">Header Offset</p></th>
<td class="tableblock halign-left valign-top"><p class="tableblock">0</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">1</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">2</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">3</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">4</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">5</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">6</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">7</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">8</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">9</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">10</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">11</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">12</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">13</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">14</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">15</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">16</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">17</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">18</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">19</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">20</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">21</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">22</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">23</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">24</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">25</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">26</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">27</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">28</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">29</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">30</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">31</p></td>
</tr>
<tr>
<th class="tableblock halign-center valign-top" colspan="34"><p class="tableblock"><code>.pcap</code> File Header</p></th>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">0</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">0</p></td>
<td class="tableblock halign-left valign-top" colspan="32"><p class="tableblock"><strong>File Type ID</strong></p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">4</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">4</p></td>
<td class="tableblock halign-left valign-top" colspan="16"><p class="tableblock"><strong>Major Version</strong></p></td>
<td class="tableblock halign-left valign-top" colspan="16"><p class="tableblock"><strong>Minor Version</strong></p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">8</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">8</p></td>
<td class="tableblock halign-left valign-top" colspan="32"><p class="tableblock">GMT Offset</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">12</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">12</p></td>
<td class="tableblock halign-left valign-top" colspan="32"><p class="tableblock">Accuracy Delta</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">16</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">16</p></td>
<td class="tableblock halign-left valign-top" colspan="32"><p class="tableblock"><strong>Maximum Length of a Capture</strong></p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">20</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">20</p></td>
<td class="tableblock halign-left valign-top" colspan="32"><p class="tableblock"><strong>Link Layer Type</strong></p></td>
</tr>
<tr>
<th class="tableblock halign-center valign-top" colspan="34"><p class="tableblock"><code>.pcap</code> Packet Header</p></th>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">24</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">0</p></td>
<td class="tableblock halign-left valign-top" colspan="32"><p class="tableblock">UNIX Epoch</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">28</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">4</p></td>
<td class="tableblock halign-left valign-top" colspan="32"><p class="tableblock">μs from Epoch</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">32</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">8</p></td>
<td class="tableblock halign-left valign-top" colspan="32"><p class="tableblock"><strong>Length of Data Captured</strong></p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">36</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">12</p></td>
<td class="tableblock halign-left valign-top" colspan="32"><p class="tableblock">Untruncated Packet Length</p></td>
</tr>
<tr>
<th class="tableblock halign-center valign-top" colspan="34"><p class="tableblock">Ethernet Frame</p></th>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">40</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">0</p></td>
<td class="tableblock halign-left valign-top" colspan="32"><p class="tableblock">Destination MAC</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">44</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">4</p></td>
<td class="tableblock halign-left valign-top" colspan="16"><p class="tableblock">Destination MAC</p></td>
<td class="tableblock halign-left valign-top" colspan="16"><p class="tableblock">Source MAC</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">48</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">8</p></td>
<td class="tableblock halign-left valign-top" colspan="32"><p class="tableblock">Source MAC</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">52</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">12</p></td>
<td class="tableblock halign-left valign-top" colspan="16"><p class="tableblock"><strong>Ethernet Type</strong></p></td>
<td class="tableblock halign-left valign-top" colspan="16"></td>
</tr>
<tr>
<th class="tableblock halign-center valign-top" colspan="34"><p class="tableblock">IPv4 Header</p></th>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">54</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">0</p></td>
<td class="tableblock halign-left valign-top" colspan="4"><p class="tableblock"><strong>Version</strong></p></td>
<td class="tableblock halign-left valign-top" colspan="4"><p class="tableblock"><strong>IHL</strong></p></td>
<td class="tableblock halign-left valign-top" colspan="6"><p class="tableblock">DSCP</p></td>
<td class="tableblock halign-left valign-top" colspan="2"><p class="tableblock">ECN</p></td>
<td class="tableblock halign-left valign-top" colspan="16"><p class="tableblock"><strong>Total Length</strong></p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">58</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">4</p></td>
<td class="tableblock halign-left valign-top" colspan="16"><p class="tableblock">Identification</p></td>
<td class="tableblock halign-left valign-top" colspan="3"><p class="tableblock">Flags</p></td>
<td class="tableblock halign-left valign-top" colspan="13"><p class="tableblock">Fragment Offset</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">62</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">8</p></td>
<td class="tableblock halign-left valign-top" colspan="8"><p class="tableblock">Time to Live</p></td>
<td class="tableblock halign-left valign-top" colspan="8"><p class="tableblock"><strong>Protocol</strong></p></td>
<td class="tableblock halign-left valign-top" colspan="16"><p class="tableblock">Header Checksum</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">66</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">8</p></td>
<td class="tableblock halign-left valign-top" colspan="32"><p class="tableblock">Source IP Address</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">70</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">12</p></td>
<td class="tableblock halign-left valign-top" colspan="32"><p class="tableblock">Destination IP Address</p></td>
</tr>
<tr>
<th class="tableblock halign-center valign-top" colspan="34"><p class="tableblock">TCP Header</p></th>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">74</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">0</p></td>
<td class="tableblock halign-left valign-top" colspan="16"><p class="tableblock">Source Port</p></td>
<td class="tableblock halign-left valign-top" colspan="16"><p class="tableblock"><strong>Destination Port</strong></p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">78</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">4</p></td>
<td class="tableblock halign-left valign-top" colspan="32"><p class="tableblock"><strong>Sequence Number</strong></p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">82</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">8</p></td>
<td class="tableblock halign-left valign-top" colspan="32"><p class="tableblock">Acknowledgement Number</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">86</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">12</p></td>
<td class="tableblock halign-left valign-top" colspan="4"><p class="tableblock"><strong>Data Offset</strong></p></td>
<td class="tableblock halign-left valign-top" colspan="3"><p class="tableblock">Reserved</p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock"><code>N S</code></p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock"><code>C W R</code></p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock"><code>E C N</code></p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock"><code>U R G</code></p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock"><code>A C K</code></p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock"><code>P S H</code></p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock"><code>R S T</code></p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock"><code>S Y N</code></p></td>
<td class="tableblock halign-center valign-middle"><p class="tableblock"><code>F I N</code></p></td>
<td class="tableblock halign-left valign-top" colspan="16"><p class="tableblock">Window Size</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">90</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">16</p></td>
<td class="tableblock halign-left valign-top" colspan="16"><p class="tableblock">Checksum</p></td>
<td class="tableblock halign-left valign-top" colspan="16"><p class="tableblock">Urgent Pointer</p></td>
</tr>
<tr>
<th class="tableblock halign-center valign-top" colspan="34"><p class="tableblock">TLS Header : When TLS Content Type equals Application Data (23 or 0x17)</p></th>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">94</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">0</p></td>
<td class="tableblock halign-left valign-top" colspan="8"><p class="tableblock"><strong>Content Type (0x17)</strong></p></td>
<td class="tableblock halign-left valign-top" colspan="24"></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">95</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">1</p></td>
<td class="tableblock halign-left valign-top" colspan="16"><p class="tableblock">Version</p></td>
<td class="tableblock halign-left valign-top" colspan="16"><p class="tableblock"><strong>Length</strong></p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">99&#8230;&#8203;</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">5&#8230;&#8203;</p></td>
<td class="tableblock halign-left valign-top" colspan="32"><p class="tableblock"><strong>Encrypted Message&#8230;&#8203;</strong></p></td>
</tr>
</tbody>
</table>
<div class="admonitionblock tip">
<table>
<tr>
<td class="icon">
<div class="title">Tip</div>
</td>
<td class="content">
Except for the extra credit, Content Types other than 0x17 can be ignored and passed directly into the output <code>.pcap</code>.
</td>
</tr>
</table>
</div>
<div class="admonitionblock note">
<table>
<tr>
<td class="icon">
<div class="title">Note</div>
</td>
<td class="content">
For simplicity <code>.pcap</code> will only ever contain one TCP session and will only include packets from one sender.
</td>
</tr>
</table>
</div>
</div>
</div>
<div class="sect1">
<h2 id="_encrypted_message_format">Encrypted Message Format</h2>
<div class="sectionbody">
<div class="paragraph">
<p>Message will be encrypted with AES128 using the CBC block method. The cipher suite used has the IANA name
TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA256. Encryption will be covered later in the course so it&#8217;s not
expected that you&#8217;re able to decrypt and encrypt the message. A library will be provided to do this for you.
However you will need to correctly pull the payload out of the decrypted message.</p>
</div>
<div class="paragraph">
<p>For reference, the encrypted message will be structured like so:</p>
</div>
<table class="tableblock frame-all grid-all stretch">
<colgroup>
<col style="width: 5.5555%;">
<col style="width: 5.5555%;">
<col style="width: 5.5555%;">
<col style="width: 5.5555%;">
<col style="width: 5.5555%;">
<col style="width: 5.5555%;">
<col style="width: 5.5555%;">
<col style="width: 5.5555%;">
<col style="width: 5.5555%;">
<col style="width: 5.5555%;">
<col style="width: 5.5555%;">
<col style="width: 5.5555%;">
<col style="width: 5.5555%;">
<col style="width: 5.5555%;">
<col style="width: 5.5555%;">
<col style="width: 5.5555%;">
<col style="width: 5.5555%;">
<col style="width: 5.5565%;">
</colgroup>
<tbody>
<tr>
<th class="tableblock halign-left valign-top"><p class="tableblock">Offsets</p></th>
<th class="tableblock halign-left valign-top"><p class="tableblock">Octet</p></th>
<td class="tableblock halign-left valign-top" colspan="8"><p class="tableblock">0</p></td>
<td class="tableblock halign-left valign-top" colspan="8"><p class="tableblock">1</p></td>
</tr>
<tr>
<th class="tableblock halign-left valign-top"><p class="tableblock">Packet Offset</p></th>
<th class="tableblock halign-left valign-top"><p class="tableblock">Header Offset</p></th>
<td class="tableblock halign-left valign-top"><p class="tableblock">0</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">1</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">2</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">3</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">4</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">5</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">6</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">7</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">8</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">9</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">10</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">11</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">12</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">13</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">14</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">15</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">0</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">0</p></td>
<td class="tableblock halign-left valign-top" colspan="16"><p class="tableblock">Opaque IV (Initialization Vector)</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">2&#8230;&#8203;</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">2&#8230;&#8203;</p></td>
<td class="tableblock halign-left valign-top" colspan="16"><p class="tableblock">Payload&#8230;&#8203; (The Alien Packet, Padded to 16 bit boundaries)</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">n</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">n</p></td>
<td class="tableblock halign-left valign-top" colspan="16"><p class="tableblock">Opaque MAC (SHA256 hash)</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">n+2</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">n+2</p></td>
<td class="tableblock halign-left valign-top" colspan="16"><p class="tableblock">Opaque MAC (SHA256 hash)</p></td>
</tr>
</tbody>
</table>
</div>
</div>
<div class="sect1">
<h2 id="_decrypted_message_format">Decrypted Message Format</h2>
<div class="sectionbody">
<div class="sect2">
<h3 id="_alien_packet_header">Alien Packet Header</h3>
<div class="paragraph">
<p>Consistent header for all decrypted alien packets.</p>
</div>
<table class="tableblock frame-all grid-all stretch">
<colgroup>
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9437%;">
</colgroup>
<tbody>
<tr>
<th class="tableblock halign-left valign-top"><p class="tableblock">Offsets</p></th>
<th class="tableblock halign-left valign-top"><p class="tableblock">Octet</p></th>
<td class="tableblock halign-left valign-top" colspan="8"><p class="tableblock">0</p></td>
<td class="tableblock halign-left valign-top" colspan="8"><p class="tableblock">1</p></td>
<td class="tableblock halign-left valign-top" colspan="8"><p class="tableblock">2</p></td>
<td class="tableblock halign-left valign-top" colspan="8"><p class="tableblock">3</p></td>
</tr>
<tr>
<th class="tableblock halign-left valign-top"><p class="tableblock">Packet Offset</p></th>
<th class="tableblock halign-left valign-top"><p class="tableblock">Header Offset</p></th>
<td class="tableblock halign-left valign-top"><p class="tableblock">0</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">1</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">2</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">3</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">4</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">5</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">6</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">7</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">8</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">9</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">10</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">11</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">12</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">13</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">14</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">15</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">16</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">17</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">18</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">19</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">20</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">21</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">22</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">23</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">24</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">25</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">26</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">27</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">28</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">29</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">30</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">31</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">0</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">0</p></td>
<td class="tableblock halign-left valign-top" colspan="4"><p class="tableblock">Version</p></td>
<td class="tableblock halign-left valign-top" colspan="4"><p class="tableblock">Type</p></td>
<td class="tableblock halign-left valign-top" colspan="24"><p class="tableblock">Total Length</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">4</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">4</p></td>
<td class="tableblock halign-left valign-top" colspan="16"><p class="tableblock">Source ID</p></td>
<td class="tableblock halign-left valign-top" colspan="16"><p class="tableblock">Destination ID</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">8</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">8</p></td>
<td class="tableblock halign-left valign-top" colspan="32"><p class="tableblock">Sequence ID</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">12&#8230;&#8203;</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">12&#8230;&#8203;</p></td>
<td class="tableblock halign-left valign-top" colspan="32"><p class="tableblock">Payload&#8230;&#8203;</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">n</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">n</p></td>
<td class="tableblock halign-left valign-top" colspan="32"><p class="tableblock">Padding to 16bit boundary</p></td>
</tr>
</tbody>
</table>
<table class="tableblock frame-all grid-all stretch">
<colgroup>
<col style="width: 20%;">
<col style="width: 13.3333%;">
<col style="width: 66.6667%;">
</colgroup>
<tbody>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Field</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Type</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Description</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Version</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">uint4</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Version of packet format. This document and the programs
                                        written for it are in support of version 1.</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Type</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">uint4</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Type of payload, either 0 = Message or 1 = Movement</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Total Length</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">uint24</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Length of the packet in octets/bytes, including the fixed header.</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Source ID</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">uint16</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">This source ID we believe to be the alien homeworld, this will always be 1.</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Destination ID</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">uint16</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">Each squadron in the armada has it&#8217;s own ID.
                                        This is the ID of the squadron to whom the packet is being sent.</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Sequence ID</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">uint32</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">A monotonically increasing ID for a given sender/receiver pair.</p></td>
</tr>
</tbody>
</table>
<div class="admonitionblock note">
<table>
<tr>
<td class="icon">
<div class="title">Note</div>
</td>
<td class="content">
Don&#8217;t forget to update the Sequence ID when the movements are reversed.
</td>
</tr>
</table>
</div>
</div>
<div class="sect2">
<h3 id="_alien_message_payload">Alien Message Payload</h3>
<div class="paragraph">
<p>Type = 0</p>
</div>
<table class="tableblock frame-all grid-all stretch">
<colgroup>
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9437%;">
</colgroup>
<tbody>
<tr>
<th class="tableblock halign-left valign-top"><p class="tableblock">Offsets</p></th>
<th class="tableblock halign-left valign-top"><p class="tableblock">Octet</p></th>
<td class="tableblock halign-left valign-top" colspan="8"><p class="tableblock">0</p></td>
<td class="tableblock halign-left valign-top" colspan="8"><p class="tableblock">1</p></td>
<td class="tableblock halign-left valign-top" colspan="8"><p class="tableblock">2</p></td>
<td class="tableblock halign-left valign-top" colspan="8"><p class="tableblock">3</p></td>
</tr>
<tr>
<th class="tableblock halign-left valign-top"><p class="tableblock">Packet Offset</p></th>
<th class="tableblock halign-left valign-top"><p class="tableblock">Payload Offset</p></th>
<td class="tableblock halign-left valign-top"><p class="tableblock">0</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">1</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">2</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">3</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">4</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">5</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">6</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">7</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">8</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">9</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">10</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">11</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">12</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">13</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">14</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">15</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">16</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">17</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">18</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">19</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">20</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">21</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">22</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">23</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">24</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">25</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">26</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">27</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">28</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">29</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">30</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">31</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">12&#8230;&#8203;</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">0&#8230;&#8203;</p></td>
<td class="tableblock halign-left valign-top" colspan="32"><p class="tableblock">Message&#8230;&#8203;</p></td>
</tr>
</tbody>
</table>
<table class="tableblock frame-all grid-all stretch">
<colgroup>
<col style="width: 20%;">
<col style="width: 13.3333%;">
<col style="width: 66.6667%;">
</colgroup>
<thead>
<tr>
<th class="tableblock halign-left valign-top">Field</th>
<th class="tableblock halign-left valign-top">Type</th>
<th class="tableblock halign-left valign-top">Description</th>
</tr>
</thead>
<tbody>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Message</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">char[]</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">ASCII-encoded string. <strong><em>NOT</em></strong> NULL-terminated.</p></td>
</tr>
</tbody>
</table>
<div class="paragraph">
<p>When a message payload is encountered the message should be printed to <code>STDOUT</code> preceded by the Destination ID.
The message should be rewritten into the frame with <code>"Don't "</code> prepended to the message with the first character lowercased.</p>
</div>
<div class="admonitionblock warning">
<table>
<tr>
<td class="icon">
<div class="title">Warning</div>
</td>
<td class="content">
Don&#8217;t forget to readjust the padding to take into account the change in message length. (see <a href="https://tools.ietf.org/html/rfc5246">rfc5246</a> for padding info)
</td>
</tr>
</table>
</div>
<div class="sect3">
<h4 id="_example">Example</h4>
<div class="literalblock">
<div class="title">Input</div>
<div class="content">
<pre>Message : "Arm torpeedoes."</pre>
</div>
</div>
<div class="literalblock">
<div class="title">Output</div>
<div class="content">
<pre>STDOUT  : "Arm torpedoes"
Message : "Don't arm torpedoes."</pre>
</div>
</div>
</div>
</div>
<div class="sect2">
<h3 id="_alien_movement_payload">Alien Movement Payload</h3>
<div class="paragraph">
<p>Type = 1</p>
</div>
<table class="tableblock frame-all grid-all stretch">
<colgroup>
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9411%;">
<col style="width: 2.9437%;">
</colgroup>
<tbody>
<tr>
<th class="tableblock halign-left valign-top"><p class="tableblock">Offsets</p></th>
<th class="tableblock halign-left valign-top"><p class="tableblock">Octet</p></th>
<td class="tableblock halign-left valign-top" colspan="8"><p class="tableblock">0</p></td>
<td class="tableblock halign-left valign-top" colspan="8"><p class="tableblock">1</p></td>
<td class="tableblock halign-left valign-top" colspan="8"><p class="tableblock">2</p></td>
<td class="tableblock halign-left valign-top" colspan="8"><p class="tableblock">3</p></td>
</tr>
<tr>
<th class="tableblock halign-left valign-top"><p class="tableblock">Packet Offset</p></th>
<th class="tableblock halign-left valign-top"><p class="tableblock">Payload Offset</p></th>
<td class="tableblock halign-left valign-top"><p class="tableblock">0</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">1</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">2</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">3</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">4</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">5</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">6</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">7</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">8</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">9</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">10</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">11</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">12</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">13</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">14</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">15</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">16</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">17</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">18</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">19</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">20</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">21</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">22</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">23</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">24</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">25</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">26</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">27</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">28</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">29</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">30</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">31</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">12</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">0</p></td>
<td class="tableblock halign-left valign-top" colspan="32"><p class="tableblock">Galactic Azimuth</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">16</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">4</p></td>
<td class="tableblock halign-left valign-top" colspan="32"><p class="tableblock">Galactic Azimuth (cont.)</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">20</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">8</p></td>
<td class="tableblock halign-left valign-top" colspan="32"><p class="tableblock">Galactic Inclination</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">24</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">12</p></td>
<td class="tableblock halign-left valign-top" colspan="32"><p class="tableblock">Galactic Inclination (cont.)</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">28</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">16</p></td>
<td class="tableblock halign-left valign-top" colspan="32"><p class="tableblock">Distance</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">32</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">20</p></td>
<td class="tableblock halign-left valign-top" colspan="32"><p class="tableblock">Speed</p></td>
</tr>
</tbody>
</table>
<table class="tableblock frame-all grid-all stretch">
<colgroup>
<col style="width: 20%;">
<col style="width: 13.3333%;">
<col style="width: 66.6667%;">
</colgroup>
<thead>
<tr>
<th class="tableblock halign-left valign-top">Field</th>
<th class="tableblock halign-left valign-top">Type</th>
<th class="tableblock halign-left valign-top">Description</th>
</tr>
</thead>
<tbody>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Galactic Azimuth</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">double</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">A IEEE 754 double-precision decimal (aka binary64), measured in degrees.</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Galactic Inclination</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">double</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">A IEEE 754 double-precision decimal (aka binary64), measured in degrees.</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Distance</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">float</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">A IEEE 754 single-precision decimal (aka binary32), measured in meters.</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Speed</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">float</p></td>
<td class="tableblock halign-left valign-top"><p class="tableblock">A IEEE 754 single-precision decimal (aka binary32), measured in meters/second.</p></td>
</tr>
</tbody>
</table>
<div class="sect3">
<h4 id="_reversing_movement_payload">Reversing Movement Payload</h4>
<div class="paragraph">
<p>Add 180 degrees both the Azimuth and Inclination. Azimuth and Inclination are bounded to [0 to 360) degrees
(zero inclusive, 360 exclusive). Azimuth and Inclination are relative to true North and Horizon, not the local reference of the target.
Distance and Speed should be kept the same.</p>
</div>
<div class="admonitionblock warning">
<table>
<tr>
<td class="icon">
<div class="title">Warning</div>
</td>
<td class="content">
Alien movements might not be in order in the input <code>.pcap</code>. Make sure to verify the sequence IDs in the Alien Packet Header.
</td>
</tr>
</table>
</div>
<div class="sect4">
<h5 id="_example_2">Example</h5>
<div class="literalblock">
<div class="title">Input</div>
<div class="content">
<pre>Galactic Azimuth      : 120.0
Galactic Inclination  : 330.0
Distance              : 123.0
Speed                 : 50.0</pre>
</div>
</div>
<div class="literalblock">
<div class="title">Output</div>
<div class="content">
<pre>Galactic Azimuth      : 300.0
Galactic Inclination  : 150.0
Distance              : 123.0
Speed                 : 50.0</pre>
</div>
</div>
</div>
</div>
</div>
</div>
</div>
<div class="sect1">
<h2 id="_provided_materials">Provided Materials</h2>
<div class="sectionbody">
<div class="paragraph">
<p>The starter kit includes the following materials:</p>
</div>
<div class="ulist">
<ul>
<li>
<p>Encryption/Decryption libarary with <code>README.md</code>.</p>
</li>
<li>
<p>Various example input <code>.pcap</code> files, with corresponding decryption keys.</p>
</li>
<li>
<p>Corresponding example decrypted <code>.pcap</code> files. Technically invalid, but show decrypted ciphertext in place.</p>
</li>
<li>
<p>Corresponding example output <code>.pcap</code> files with re-encrypted TLS.</p>
</li>
<li>
<p><code>generator</code> executable can be used to generate an input <code>.pcap</code></p>
</li>
</ul>
</div>
</div>
</div>
<div class="sect1">
<h2 id="_suggested_extra_credit">Suggested Extra Credit</h2>
<div class="sectionbody">
<table class="tableblock frame-all grid-all stretch">
<colgroup>
<col style="width: 16.6666%;">
<col style="width: 77.7777%;">
<col style="width: 5.5557%;">
</colgroup>
<thead>
<tr>
<th class="tableblock halign-center valign-top">Area</th>
<th class="tableblock halign-center valign-top">Feature</th>
<th class="tableblock halign-center valign-top">+</th>
</tr>
</thead>
<tbody>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Document</p></td>
<td class="tableblock halign-left valign-top"><div class="content"><div class="paragraph">
<p>Write a <code>man(1)</code> page to document the program.</p>
</div></div></td>
<td class="tableblock halign-center valign-top"><p class="tableblock">+2</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Implement</p></td>
<td class="tableblock halign-left valign-top"><div class="content"><div class="paragraph">
<p>Update the TCP sequence numbers to reflect the new packet sizes as well.</p>
</div></div></td>
<td class="tableblock halign-center valign-top"><p class="tableblock">+2</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Implement</p></td>
<td class="tableblock halign-left valign-top"><div class="content"><div class="paragraph">
<p>Update the SHA256 MAC in the TLS frame (see <a href="https://tools.ietf.org/html/rfc7366">RFC7366</a>).</p>
</div></div></td>
<td class="tableblock halign-center valign-top"><p class="tableblock">+3</p></td>
</tr>
<tr>
<td class="tableblock halign-left valign-top"><p class="tableblock">Implement</p></td>
<td class="tableblock halign-left valign-top"><div class="content"><div class="paragraph">
<p>Update checksum in the TCP frame (see <a href="https://tools.ietf.org/html/rfc793">RFC793</a>).</p>
</div></div></td>
<td class="tableblock halign-center valign-top"><p class="tableblock">+5</p></td>
</tr>
</tbody>
</table>
</div>
</div>
</div>
<div id="footer">
<div id="footer-text">
Last updated 2022-10-06 14:52:39 -0400
</div>
</div>
</body>
</html>
