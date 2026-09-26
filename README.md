# bare-app-kit

AppKit for Bare on macOS. It gives you AppKit's windows, views and controls in JavaScript, along with a runtime that starts the application for you, so a Bare app can have a native Mac window.

```
npm i bare-app-kit
```

## Usage

```js
const { Application, Window, Button, TextField, defaultMenu } = require('bare-app-kit')

Application.mainMenu = defaultMenu('Hello')

const window = new Window({
  width: 400,
  height: 200,
  styleMask: Window.STYLE_MASK.TITLED | Window.STYLE_MASK.CLOSABLE
})

window.title = 'Hello'

const field = new TextField({ x: 20, y: 140, width: 360, height: 24 })

field.placeholderString = 'Your name'

const button = new Button({ x: 20, y: 100, width: 120, height: 32 })

button.title = 'Greet'

button.on('click', () => {
  window.title = `Hello, ${field.stringValue || 'stranger'}`
})

window.contentView.addSubview(field)
window.contentView.addSubview(button)
window.makeKeyAndOrderFront()
```

Build the app with `bare-build` and this runtime:

```console
bare-build --host darwin-arm64 --runtime bare-app-kit/runtime --identifier com.example.Hello index.js
```

Views are laid out from the top left, in points. Objects that have events, such as windows, controls and menu items, emit them as ordinary events. AppKit is only asked to report an event while something listens to it.

## License

Apache-2.0
