#pragma once

const char* htmlString()
{
	return R"(
<html>
	<head>
		<title>Remote Inspector</title>
		<meta http-equiv='Content-Type' content='text/html; charset=utf-8' />
		<style>
			h2 {
				font-size: 2rem;
				font-weight: 600;
				line-height: 1.125;
			}

			html {
				background: #2a2b36;
				font-size: 11pt;
				color: #cacad8;
				padding: 20px 20px 0 20px;
			}

			body {
				padding: 0em 3em;
			}

			body, button, input, select, textarea {
				font-family: BlinkMacSystemFont, -apple-system, 'Segoe UI', 
										 'Roboto', 'Ubuntu', 'Helvetica Neue', 'Helvetica', 'Arial', sans-serif;
			}

			.status {
				margin-bottom: 30px;
				padding: 1em;
				background: rgb(2 16 5 / 36%);
				border-radius: 8px;
				box-shadow: 0 0.5em 1em -0.125em rgb(10 10 10 / 30%), 0 0 0 1px rgb(10 10 10 / 2%);
			}

			input {
				width: calc(100% - .4em); 
				padding: 8px;
			}

			.panel {
				border-radius: 8px;
				box-shadow: 0 0.5em 1em -0.125em rgb(10 10 10 / 30%), 0 0 0 1px rgb(10 10 10 / 2%);
				font-size: 1rem;
				border: 1px solid #4d0a9b;
				border: 1px solid #181921;
				overflow: hidden;
			}

			.panel-block {
				color: #fff;
				padding: 0.0em 0.75em;
				background: linear-gradient(180deg, #00000038, transparent);
				padding: 1em 1em;
				display: flex;
			}

			.panel-block div:nth-child(1) {
				width: 100%;
			}
			
			.panel-block div:nth-child(2) {
				width: 150px;
				flex: 0 0 150px;
			}

			.panel-block p {
				display: block;
				margin: 0;
				padding: 0.25em;
			}

			.panel-block:not(:last-child), .panel-tabs:not(:last-child) {
				border-bottom: 1px solid #181921;
			}

			input[type="button"] {
				background: linear-gradient(180deg, #e7e9fa 20%, #757889);
				color: #e1c5ff;
				color: #333;
				text-shadow: 0px 1px #d5d7e8;
				border-radius: 100px;
				border: none;
				box-shadow: 0 0.5em 1em -0.125em rgb(10 10 10 / 30%), 0 0 0 1px rgb(10 10 10 / 2%);
				padding: 0.6em;
				font-size: 1em;
				font-weight: bold;
				margin-top: 0.2em;
				margin-left: 0.4em; 
				cursor: pointer;
			}

			input[type="button"]:active {
				background: linear-gradient(0deg, #d6d9ec, #757889);
				box-shadow: none;
			}
		</style>
	</head>
	<body>
		<h2>Remote Inspector</h2>
		<div class='status'>
			Make sure the remote inspector server is started up in your target before clicking "Connect".
		</div>

		<div id="targets">
			<nav class="panel">
				<div class="panel-block">
					<div>
						<p><input type="text" value="127.0.0.1:19998" id="address" /></p>
					</div>
					<div>
						<input type="button" value="Connect" id="connect" />
					</div>
				</div>
			</nav>
		</div>

		<script>
			document.getElementById("connect").addEventListener("click", () => {
				const address = document.getElementById("address").value; console.log(address);
				document.location.assign("inspector://" + address);
			})
		</script>
	</body>
</html>
)";
}
