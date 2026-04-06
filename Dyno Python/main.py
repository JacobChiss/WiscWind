import dash
from dash import html, dcc, callback, Output, Input

app = dash.Dash(__name__)

app.layout = html.Div([
    html.H1("Wind Emulator Control Panel"),
    html.Label("Wind Speed (m/s)"),
    dcc.Slider(id='wind-speed', min=0, max=20, step=0.5, value=5),
    html.Div(id='output')
])

@callback(
    Output('output', 'children'),
    Input('wind-speed', 'value')
)
def update_output(wind_speed):
    blade_radius = 0.15
    tsr = 5.0
    target_rpm = (wind_speed * tsr * 60) / (2 * 3.14159 * blade_radius)
    return f"Wind Speed: {wind_speed} m/s → Target RPM: {target_rpm:.1f}"

if __name__ == '__main__':
    app.run(debug=True)