<!doctype html>
<html lang="en">
<head>
  <meta charset="utf-8" />
  <meta name="viewport" content="width=device-width,initial-scale=1" />
  <title>Hardware Projects — Quadcopter</title>
  <style>
    /* Simple, readable styling suitable for GitHub Pages */
    :root{
      --bg:#0f1724;
      --card:#0b1220;
      --muted:#9aa4b2;
      --accent:#7dd3fc;
      --white:#f8fafc;
      --glass: rgba(255,255,255,0.03);
      font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, "Helvetica Neue", Arial;
    }
    html,body{height:100%;}
    body{
      margin:0;
      padding:32px;
      background: linear-gradient(180deg,var(--bg), #071024);
      color:var(--white);
      -webkit-font-smoothing:antialiased;
      -moz-osx-font-smoothing:grayscale;
    }

    .container{
      max-width:900px;
      margin:0 auto;
    }

    header{
      display:flex;
      flex-direction:column;
      gap:8px;
      margin-bottom:20px;
    }
    h1{
      margin:0;
      font-size:20px;
      letter-spacing:0.6px;
    }
    .meta{
      color:var(--muted);
      font-size:13px;
    }

    .card{
      background:linear-gradient(180deg, rgba(255,255,255,0.02), rgba(255,255,255,0.01));
      border-radius:12px;
      padding:18px;
      box-shadow: 0 6px 18px rgba(2,6,23,0.6);
      border:1px solid rgba(255,255,255,0.03);
      margin-bottom:18px;
    }

    .section-title{
      display:flex;
      align-items:center;
      justify-content:space-between;
      gap:12px;
      margin-bottom:10px;
    }
    .section-title h2{
      margin:0;
      font-size:14px;
    }
    .tag{
      font-size:12px;
      color:var(--muted);
      background:var(--glass);
      padding:6px 8px;
      border-radius:8px;
    }

    pre.ascii{
      background:transparent;
      color:var(--muted);
      font-family: ui-monospace, SFMono-Regular, Menlo, Monaco, "Roboto Mono", monospace;
      font-size:12px;
      overflow:auto;
      margin:0 0 12px 0;
    }

    ul.parts{
      margin:0;
      padding-left:18px;
      line-height:1.6;
      color:var(--white);
    }

    .controls{
      display:flex;
      gap:8px;
      align-items:center;
    }
    button.copy{
      background:transparent;
      border:1px solid rgba(255,255,255,0.06);
      color:var(--accent);
      padding:6px 10px;
      border-radius:8px;
      cursor:pointer;
      font-size:13px;
      backdrop-filter: blur(4px);
    }
    button.copy:active{transform:translateY(1px)}
    footer{
      color:var(--muted);
      font-size:13px;
      margin-top:18px;
      text-align:center;
    }

    @media (min-width:720px){
      .two-col{
        display:grid;
        grid-template-columns: 1fr 1fr;
        gap:14px;
      }
    }
  </style>
</head>
<body>
  <div class="container">
    <header>
      <h1>HARDWARE PROJECTS</h1>
      <div class="meta">Initialized on <strong>17/08/2025</strong></div>
    </header>

    <div class="card">
      <div class="section-title">
        <h2>QUADROCOPTER (HARDWARE REQUIRED)</h2>
        <div class="controls">
          <div class="tag">Status: Planned</div>
          <button class="copy" id="copyHardware">Copy hardware list</button>
        </div>
      </div>

      <pre class="ascii">=========================================================================================
</pre>

      <ul class="parts" id="hardwareList">
        <li>4 × BLDC MOTOR — 1000KV A2212/13Y</li>
        <li>4 × ESC — 30 AMP</li>
        <li>1 × 2200mAh Lithium battery</li>
        <li>1 × XT60/XT6050 connector (M/F)</li>
        <li>4 × 10-inch propellers</li>
        <li>1 × Arduino UNO</li>
        <li>Jumper wires (MtM, MtF, FtF)</li>
        <li>FlySky FS-i6 (6-channel transmitter and receiver / flight controller)</li>
      </ul>

      <pre class="ascii">=========================================================================================
</pre>
      <div style="color:var(--muted); font-size:13px; margin-top:8px;">
        Notes: adjust motor/ESC specs to match frame weight and battery C-rating. Confirm connector type (XT60 vs XT6050) before ordering.
      </div>
    </div>

    <div class="two-col">
      <div class="card">
        <div class="section-title">
          <h2>QUADROCOPTER (SOFTWARE)</h2>
          <div class="tag">TODO</div>
        </div>
        <p style="color:var(--muted); margin:0;">
          Add software stack details here (flight controller firmware, autopilot, companion computer, ground control station, PID tuning steps, etc.).
        </p>
      </div>

      <div class="card">
        <div class="section-title">
          <h2>PROJECT METADATA</h2>
          <div class="tag">Project</div>
        </div>

        <ul style="margin:0; padding-left:18px; color:var(--muted); line-height:1.6;">
          <li><strong>Initialized:</strong> 17/08/2025</li>
          <li><strong>Category:</strong> Hardware / Embedded</li>
          <li><strong>Next steps:</strong> Frame selection → ESC calibration → Motor test → Software integration</li>
        </ul>
      </div>
    </div>

    <footer>
      Tip: to publish this page via GitHub Pages, put this file in the repository root (or `docs/`) and enable Pages in repository settings.
    </footer>
  </div>

  <script>
    // copy-to-clipboard for the hardware list (text-only)
    document.getElementById('copyHardware').addEventListener('click', function(){
      const items = Array.from(document.querySelectorAll('#hardwareList li')).map(li => "-> " + li.textContent.trim());
      const text = items.join("\\n");
      navigator.clipboard?.writeText(text).then(() => {
        const prev = this.textContent;
        this.textContent = "Copied!";
        setTimeout(() => this.textContent = prev, 1500);
      }).catch(() => {
        alert('Unable to copy automatically. Select the list and press Ctrl/Cmd+C.');
      });
    });
  </script>
</body>
</html>
